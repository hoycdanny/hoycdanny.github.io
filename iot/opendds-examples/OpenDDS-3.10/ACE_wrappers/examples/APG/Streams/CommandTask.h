/* -*- C++ -*- */
// $Id: CommandTask.h 14 2007-02-01 15:49:12Z mitza $

#ifndef COMMAND_TASK_H
#define COMMAND_TASK_H

#include "ace/Task.h"
#include "ace/Module.h"

#include "Command.h"

// Listing 01 code/ch18
class CommandTask : public ACE_Task<ACE_MT_SYNCH>
{
public:
  typedef ACE_Task<ACE_MT_SYNCH> inherited;

  virtual ~CommandTask () { }

  virtual int open (void * = 0 );

  int put (ACE_Message_Block *message,
           ACE_Time_Value *timeout);

  virtual int svc (void);

  virtual int close (u_long flags);

protected:
  CommandTask (int command);

  virtual int process (Command *message);

  int command_;
};
// Listing 01


#endif /* COMMAND_TASK_H */
