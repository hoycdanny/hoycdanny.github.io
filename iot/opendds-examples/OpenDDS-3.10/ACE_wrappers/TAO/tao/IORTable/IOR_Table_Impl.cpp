/**
 * @file IOR_Table_Impl.cpp
 *
 * $Id: IOR_Table_Impl.cpp 2646 2015-08-28 00:38:05Z mesnierp $
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 *
 */

#include "tao/IORTable/IOR_Table_Impl.h"
#include "tao/PortableServer/ForwardRequestC.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/Stub.h"
#include "tao/MProfile.h"
#include "tao/Profile.h"
#include "tao/Acceptor_Registry.h"
#include "tao/Transport_Acceptor.h"
#include "tao/Thread_Lane_Resources.h"
#include "ace/Guard_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_IOR_Table_Impl_ptr
TAO::Objref_Traits <TAO_IOR_Table_Impl>::duplicate (TAO_IOR_Table_Impl_ptr p)
{
  if (!::CORBA::is_nil (p))
    {
      p->_add_ref ();
    }

  return p;
}

void
TAO::Objref_Traits <TAO_IOR_Table_Impl>::release (TAO_IOR_Table_Impl_ptr p)
{
  ::CORBA::release (p);
}

TAO_IOR_Table_Impl_ptr
TAO::Objref_Traits <TAO_IOR_Table_Impl>::nil (void)
{
  return TAO_IOR_Table_Impl::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits <TAO_IOR_Table_Impl>::marshal (const TAO_IOR_Table_Impl_ptr,
                                                  TAO_OutputCDR &)
{
  return false;
}

TAO_IOR_Table_Impl::TAO_IOR_Table_Impl (TAO_ORB_Core &orb_core)
  : orb_core_ (orb_core)
  , map_ ()
  , locator_ ()
  , lock_ ()
  , use_refresh_ (orb_core.resource_factory ()->refresh_IORTable ())
{
}

bool
TAO_IOR_Table_Impl::refresh (ACE_CString &ior)
{
  CORBA::Object_var obj =
    this->orb_core_.orb ()->string_to_object (ior.c_str ());
  TAO_MProfile *prof = obj->_stubobj ()->make_profiles ();
  bool result = false;
  TAO_Acceptor_Registry &ar =
    this->orb_core_.lane_resources().acceptor_registry ();
  for (TAO_Acceptor** acceptor = ar.begin();
       acceptor != ar.end();
       ++acceptor)
    {
      if ((*acceptor)->refresh (*prof))
        {
          result = true;
        }
    }
  if (result)
    {
      for (CORBA::ULong i = 0; i < prof->profile_count (); ++i)
        {
          TAO_Profile *profile = prof->get_profile (i);
          profile->tagged_components ().remove_component (IOP::TAG_ALTERNATE_IIOP_ADDRESS);
          if (profile->encode_alternate_endpoints () == -1)
            result = false;
        }
    }
  if (result)
    {
      obj->_stubobj ()->base_profiles (*prof);
      ior = this->orb_core_.orb ()->object_to_string (obj.in ());
    }
  delete prof;
  return result;
}

char *
TAO_IOR_Table_Impl::find (const char *object_key)
{
  // We don't want the lock held during locate, so make it go out
  // of scope before then.
  {
    ACE_CString key (object_key);
    ACE_CString ior;

    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->lock_, 0);
    if (this->map_.find (key, ior) == 0)
      {
        if (this->use_refresh_ && this->refresh (ior))
          {
            this->map_.rebind (key, ior);
          }
        return CORBA::string_dup (ior.c_str ());
      }
    if (CORBA::is_nil (this->locator_.in ()))
      throw IORTable::NotFound ();
  }

  return this->locator_->locate (object_key);
}

void
TAO_IOR_Table_Impl::bind (const char * object_key, const char * IOR)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
  if (this->map_.bind (object_key, IOR) != 0)
    throw IORTable::AlreadyBound ();
}

void
TAO_IOR_Table_Impl::rebind (const char * object_key, const char * IOR)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
  this->map_.rebind (object_key, IOR);
}

void
TAO_IOR_Table_Impl::unbind (const char * object_key)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
  if (this->map_.unbind (object_key) != 0)
    throw IORTable::NotFound ();
}

void
TAO_IOR_Table_Impl::set_locator (IORTable::Locator_ptr locator)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->lock_);
  this->locator_ = IORTable::Locator::_duplicate (locator);
}

void
TAO_IOR_Table_Impl::refresh (CORBA::Boolean enable)
{
  this->use_refresh_ = enable;
}

TAO_END_VERSIONED_NAMESPACE_DECL
