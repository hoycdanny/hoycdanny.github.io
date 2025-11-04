
//=============================================================================
/**
 *  @file   test_i.h
 *
 *  $Id: test_i.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================


#ifndef TAO_BUFFERED_AMI_TEST_I_H
#define TAO_BUFFERED_AMI_TEST_I_H

#include "testS.h"

/**
 * @class test_i
 *
 * @brief Simple implementation.
 */
class test_i : public POA_test
{
public:
  /// ctor.
  test_i (CORBA::ORB_ptr orb);

  // = The test interface methods.
  void method (CORBA::ULong request_number,
               CORBA::ULong_out reply_number);

  void shutdown (void);

private:
  /// The ORB.
  CORBA::ORB_var orb_;
};

#endif /* TAO_BUFFERED_AMI_TEST_I_H */
