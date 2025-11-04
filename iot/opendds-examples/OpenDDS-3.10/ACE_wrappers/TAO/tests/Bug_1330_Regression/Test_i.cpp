//
// $Id: Test_i.cpp 2179 2013-05-28 22:16:51Z mesnierp $
//
#include "Test_i.h"

Test_i::Test_i(CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

Test_i::~Test_i()
{
}

void
Test_i::test_method (void)
{
}

void
Test_i::shutdown (void)
{
  this->orb_->shutdown (0);
}
