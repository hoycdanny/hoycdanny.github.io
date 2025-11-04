/* -*- C++ -*- $Id: Test_i.h 2185 2013-06-05 17:01:18Z mesnierp $ */

#ifndef TEST_I_H_
#define TEST_I_H_

#include "TestS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  Test_i : public virtual POA_Test
{
public:
  Test_i (short server_num);
  virtual ~Test_i ();

  virtual CORBA::Short get_server_num (CORBA::Short delay_secs);

private:
  CORBA::Short server_num_;
};

#endif /* TEST_I_H_ */
