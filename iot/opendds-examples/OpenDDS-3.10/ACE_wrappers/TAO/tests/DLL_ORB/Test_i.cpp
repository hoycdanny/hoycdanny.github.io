// -*- C++ -*-
// $Id: Test_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Test_i.h"

Test_i::Test_i (void)
  : orb_ ()
{
}

void
Test_i::invoke_me ( /* */)
{
  ACE_DEBUG ((LM_INFO,
              "(%P|%t) Test method invoked.\n"));
}

void
Test_i::shutdown (void)
{
  ACE_DEBUG ((LM_INFO,
              "Server is shutting down.\n"));

  if (!CORBA::is_nil (this->orb_.in ()))
    this->orb_->shutdown (0);
}

void
Test_i::orb (CORBA::ORB_ptr orb)
{
  this->orb_ = CORBA::ORB::_duplicate (orb);
}
