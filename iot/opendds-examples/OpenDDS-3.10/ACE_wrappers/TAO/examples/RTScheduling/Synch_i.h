//$Id: Synch_i.h 935 2008-12-10 21:47:27Z mitza $

#ifndef SYNCH_I_H
#define SYNCH_I_H

#include "SynchS.h"

class SYNCH_Export Synch_i : public POA_Synch
{
 public:

  Synch_i (void);
  virtual void go (CORBA::Long base_time);

  int synched (void);

  ACE_Time_Value* base_time (void);

 private:
  int synched_;
  ACE_Time_Value base_time_;
};

#endif /*SYNCH_I_H*/
