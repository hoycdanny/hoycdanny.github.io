//
// $Id: simple_test_i.cpp 2179 2013-05-28 22:16:51Z mesnierp $
//

#include "simple_test_i.h"

Simple_Test_i::Simple_Test_i (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Simple_Test_i::shutdown (void)
{
  this->orb_->shutdown (0);
}
