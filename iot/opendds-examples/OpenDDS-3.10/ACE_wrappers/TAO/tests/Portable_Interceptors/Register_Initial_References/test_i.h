// -*- C++ -*-

//=============================================================================
/**
 * @file test_i.h
 *
 * $Id: test_i.h 14 2007-02-01 15:49:12Z mitza $
 *
 * @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TEST_I_H
#define TEST_I_H

#include "testS.h"

/**
 * @class test_i
 *
 * @brief Simple test class.
 *
 * This class implements the "test" interface used in this test.
 */
class test_i : public virtual POA_TestModule::test
{
public:

  /// Constructor.
  test_i (void);

  /// Destructor.
  ~test_i (void);

private:
};

#endif  /* TEST_I_H */
