// $Id: test_i.h 2363 2014-09-12 14:50:12Z mesnierp $
#ifndef IMR_RECONNECTSERVER_H
#define IMR_RECONNECTSERVER_H

#include "testS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


class  Test_Dummy_i
  : public virtual POA_Test::Dummy
{
public:
  // Constructor
  Test_Dummy_i (void);

  // Destructor
  virtual ~Test_Dummy_i (void);

  virtual  char * getMessage (void);
};

class  Test_Time_i
  : public virtual POA_Test::Time
{
public:
  // Constructor
  Test_Time_i (void);

  // Destructor
  virtual ~Test_Time_i (void);

  virtual
  ::CORBA::Long current_time (
      void
    );

  virtual
  void shutdown (
      void
    );
};


#endif /* IMR_RECONNECTSERVER_H  */

