// $Id: Server_Worker.cpp 935 2008-12-10 21:47:27Z mitza $
#include "Server_Worker.h"

Server_Worker::Server_Worker (CORBA::ORB_ptr orb)
  :  orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
Server_Worker::svc (void)
{
  try
    {
      this->orb_->run ();
    }
  catch (const CORBA::Exception&)
    {
    }
  return 0;
}
