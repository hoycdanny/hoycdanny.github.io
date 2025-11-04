// -*- C++ -*-
// $Id: test_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "test_i.h"

test_i::test_i (CORBA::Short num,
                CORBA::ORB_ptr orb)
  : number_ (num),
    orb_ (CORBA::ORB::_duplicate (orb))
{
}

test_i::~test_i (void)
{
}

CORBA::Short
test_i::number (void)
{
  return this->number_;
}

void
test_i::shutdown (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "Server is shutting down via object %d.\n",
              this->number_));
  this->orb_->shutdown (0);
}
