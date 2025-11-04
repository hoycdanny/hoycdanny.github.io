/* -*- C++ -*- $Id: Terminator.h 2577 2015-06-19 21:57:06Z mesnierp $ */

#include "ace/Task_T.h"

class Terminator : public ACE_Task<ACE_MT_SYNCH>
{
 public:

  virtual int open(void*);

  virtual int svc();
};

