//
// $Id: HelloWorld.h 935 2008-12-10 21:47:27Z mitza $
//

#ifndef HELLOWORLD_H
#define HELLOWORLD_H
#include /**/ "ace/pre.h"

#include "TestS.h"

/// Implement the Test::HelloWorld interface
///
class HelloWorld
  : public virtual POA_Test::HelloWorld
{
public:

  HelloWorld (void);
  /// Constructor

  virtual char * get_string (void);

};

#include /**/ "ace/post.h"
#endif /* HELLOWORLD_H */
