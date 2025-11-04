// $Id: Client_Task.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Client_Task.h"

Client_Task::Client_Task (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Client_Task::svc (void)
{

  try
    {
      this->orb_->run ();
    }
  catch (const CORBA::Exception&)
    {
      return -1;
    }

  return 0;
}
