/**
 * @file ORB_Task.cpp
 *
 * $Id: ORB_Task.cpp 2378 2014-10-10 15:56:52Z mesnierp $
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 *
 */
#include "ORB_Task.h"
#include "tao/Environment.h"

ORB_Task::ORB_Task (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

int
ORB_Task::svc (void)
{
  try
    {
      this->orb_->run ();
    }
  catch (const CORBA::Exception& )
    {
    }
  return 0;
}
