//
// $Id: Server_Task.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//
#include "Server_Task.h"

Server_Task::Server_Task (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Server_Task::svc (void)
{
  try
    {
      this->orb_->run ();
    }
  catch (const CORBA::Exception&){}
  return 0;
}
