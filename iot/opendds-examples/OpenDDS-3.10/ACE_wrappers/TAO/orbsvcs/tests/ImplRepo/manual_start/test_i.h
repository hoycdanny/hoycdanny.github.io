/* -*- C++ -*- $Id: test_i.h 2390 2014-10-23 22:23:27Z mesnierp $ */

#ifndef TEST_I_H_
#define TEST_I_H_

#include "testS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class  Test_i : public virtual POA_Test
{
public:
  //Constructor
  Test_i (void);

  //Destructor
  virtual ~Test_i (void);

  virtual void contact (void);

private:
};

#endif /* TEST_I_H_ */
