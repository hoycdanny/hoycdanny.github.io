// $Id: ChildServant.cpp 935 2008-12-10 21:47:27Z mitza $

#include "ChildServant.h"

ChildServant::ChildServant(CORBA::ORB_ptr orb)
: orb_(CORBA::ORB::_duplicate(orb))
{
}

void
ChildServant::childMethod ()
{
   // No-op
}

void
ChildServant::parentMethod ()
{
   // Just throw an exception
   throw CORBA::INTERNAL ();
}

void
ChildServant::shutdown ()
{
   this->orb_->shutdown(0);
}
