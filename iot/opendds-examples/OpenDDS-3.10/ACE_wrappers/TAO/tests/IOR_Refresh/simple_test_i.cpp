//
// $Id: simple_test_i.cpp 2646 2015-08-28 00:38:05Z mesnierp $
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
