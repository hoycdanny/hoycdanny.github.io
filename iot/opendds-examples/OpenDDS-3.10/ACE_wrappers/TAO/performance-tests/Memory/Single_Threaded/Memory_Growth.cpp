//
// $Id: Memory_Growth.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//
#include "Memory_Growth.h"

Memory_Growth::Memory_Growth (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Memory_Growth::ping (void)
{
  return;
}

void
Memory_Growth::shutdown (void)
{
  this->orb_->shutdown (0);
}
