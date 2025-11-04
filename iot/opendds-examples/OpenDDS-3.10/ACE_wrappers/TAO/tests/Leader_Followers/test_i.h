
//=============================================================================
/**
 *  @file   test_i.h
 *
 *  $Id: test_i.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================


#include "testS.h"

/**
 * @class test_i
 *
 * @brief Simple test implementation.
 */
class test_i : public POA_test
{
public:
  /// ctor.
  test_i (CORBA::ORB_ptr orb);

  // = The test interface methods.
  CORBA::ULong method (CORBA::ULong work);

  void shutdown (void);

private:
  /// The ORB.
  CORBA::ORB_var orb_;
};
