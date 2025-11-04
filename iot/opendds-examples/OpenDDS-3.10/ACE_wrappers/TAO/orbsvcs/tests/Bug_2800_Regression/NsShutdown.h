//
// $Id: NsShutdown.h 2179 2013-05-28 22:16:51Z mesnierp $
//

#ifndef SHUTDOWN_H
#define SHUTDOWN_H
#include /**/ "ace/pre.h"

#include "TestS.h"

/// Implement the Test::Hello interface
class NsShutdown
  : public virtual POA_Test::NsShutdown
{
public:
  /// Constructor
  NsShutdown (CORBA::ORB_ptr orb);

  virtual void shutdown (void);

private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;
};

#include /**/ "ace/post.h"
#endif /* HELLO_H */
