// $Id: MessengerTask.h 2858 2016-06-09 15:40:28Z mesnierp $

#ifndef MESSENGERTASK_H
#define MESSENGERTASK_H

#include "tao/corba.h"
#include "ace/Task.h"

class MessengerTask : public ACE_Task_Base
{
public:
  MessengerTask();
  virtual int svc();

  void end();
private:
  CORBA::ORB_var orb_;
};

#endif
