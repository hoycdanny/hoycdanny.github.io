/* -*- C++ -*- $Id: Terminator.h 2179 2013-05-28 22:16:51Z mesnierp $ */

#include "ace/Task_T.h"

class Terminator : public ACE_Task<ACE_MT_SYNCH>
{
 public:

  virtual int open(void*);

  virtual int svc();
};

