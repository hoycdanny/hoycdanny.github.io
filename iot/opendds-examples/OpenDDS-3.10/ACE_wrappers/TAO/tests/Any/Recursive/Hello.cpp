// $Id: Hello.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Hello.h"

Hello::Hello (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

CORBA::Any *
Hello::get_any (CORBA::Any const & the_any)
{
  CORBA::Any * retval = 0;

  ACE_NEW_THROW_EX (retval,
                    CORBA::Any (the_any),
                    CORBA::NO_MEMORY ());

  return retval;
}


void
Hello::shutdown (void)
{
  this->orb_->shutdown (0);
}
