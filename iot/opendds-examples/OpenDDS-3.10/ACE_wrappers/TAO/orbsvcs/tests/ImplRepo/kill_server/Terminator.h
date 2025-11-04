/* -*- C++ -*- $Id: Terminator.h 2225 2013-12-04 23:08:11Z mesnierp $ */

#include "ace/Task_T.h"

class Terminator : public ACE_Task<ACE_MT_SYNCH>
{
 public:

  virtual int open(void*);

  virtual int svc();
};

