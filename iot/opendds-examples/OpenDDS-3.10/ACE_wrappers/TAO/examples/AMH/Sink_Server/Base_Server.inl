// $Id: Base_Server.inl 14 2007-02-01 15:49:12Z mitza $

#include "Base_Server.h"

ACE_INLINE CORBA::ORB_ptr
Base_Server::orb (void)
{
  return this->orb_.in();
}
