//
// $Id: Session_Task.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//

#include "Session_Task.h"
#include "Session.h"

Session_Task::Session_Task (Session *session)
  : session_ (session)
{
}

int
Session_Task::svc (void)
{
  return this->session_->svc ();
}
