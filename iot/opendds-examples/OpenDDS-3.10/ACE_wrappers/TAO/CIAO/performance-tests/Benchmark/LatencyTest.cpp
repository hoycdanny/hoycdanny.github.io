//
// $Id: LatencyTest.cpp 935 2008-12-10 21:47:27Z mitza $
//
#include "LatencyTest.h"

LatencyTest::LatencyTest (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}


CORBA::Long
LatencyTest::makeCall (CORBA::Long send_time)
{
  return send_time;
}

void
LatencyTest::shutdown ()
{
  this->orb_->shutdown (0);
}
