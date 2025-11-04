/* -*- C++ -*- $Id: Test_i.h 2255 2014-02-11 23:14:04Z mesnierp $ */

#ifndef TEST_I_H_
#define TEST_I_H_

#include "TestS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  Test_i : public virtual POA_Test
{
public:
  virtual CORBA::Long server_pid (void);

};

#endif /* TEST_I_H_ */
