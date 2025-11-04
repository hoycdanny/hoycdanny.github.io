//=============================================================================
/**
 *  @file    test_dynunion.h
 *
 *  $Id: test_dynunion.h 14 2007-02-01 15:49:12Z mitza $
 *
 *  Header file for class to test DynUnion.
 *
 *
 *  @author Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#if !defined (TEST_DYNUNION_H)
#define TEST_DYNUNION_H

#include "tao/ORB.h"

class Test_DynUnion
{
public:
  Test_DynUnion (CORBA::ORB_var orb, int debug);
  ~Test_DynUnion (void);

  const char* test_name (void) const;

  int run_test (void);

private:
  CORBA::ORB_var orb_;
  char* test_name_;
  CORBA::ULong error_count_;
  int debug_;
};

#endif /* TEST_DYNUNION_H */

