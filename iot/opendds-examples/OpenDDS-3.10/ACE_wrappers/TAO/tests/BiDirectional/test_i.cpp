// $Id: test_i.cpp 2371 2014-10-08 20:50:17Z mesnierp $

#include "test_i.h"

#include "tao/ORB_Core.h"
#include "tao/debug.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Thread_Lane_Resources.h"
#include "ace/OS_NS_stdlib.h"

#if !defined(__ACE_INLINE__)
#include "test_i.inl"
#endif /* __ACE_INLINE__ */

void
Callback_i::shutdown (void)
{
  ACE_DEBUG ((LM_DEBUG, "Performing clean shutdown\n"));
  this->orb_->shutdown (0);
}

void
Callback_i::callback_method ( /**/)
{
  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG, "Callback method called\n"));
  ACE_Time_Value tv (0,500);
  ACE_OS::sleep (tv);
}


// ****************************************************************

void
Invoker::callback (Callback_ptr cb)
{
  cb_ = Callback::_duplicate (cb);
}

void
Invoker::shutdown (void)
{
  cb_->shutdown ();
}

int
Invoker::svc (void)
{
  try
    {
      cb_->callback_method ();
    }
  catch (CORBA::Exception &ex)
    {
      ACE_DEBUG ((LM_DEBUG, "(%P|%t) Invoker caught %s\n", ex._name ()));
    }
  return 0;
}

CORBA::Long
Simple_Server_i::test_method (CORBA::Boolean do_callback)
{
  if (do_callback)
    {
      this->flag_ = 1;
    }

  return 0;
}

void
Simple_Server_i::callback_object (Callback_ptr callback)
{
  // Store the callback object
  this->invoker_.callback (callback);
}

int
Simple_Server_i::call_client (void)
{
  if (this->flag_)
    {
      invoker_.activate (THR_JOINABLE | THR_NEW_LWP, this->no_iterations_);
      invoker_.wait ();
      size_t csize = this->orb_->orb_core ()->lane_resources ().transport_cache ().current_size ();
      if (csize > 1)
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t) The cache has grown to %d\n", csize));
        }

      this->invoker_.shutdown ();
      this->flag_ = 0;

      return 1;
    }

  return 0;
}


void
Simple_Server_i::shutdown (void)
{
  this->orb_->shutdown (0);
}
