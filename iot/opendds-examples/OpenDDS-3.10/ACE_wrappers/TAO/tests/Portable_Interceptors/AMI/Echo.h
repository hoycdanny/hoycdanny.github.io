/**
 * @file Echo.h
 *
 * $Id: Echo.h 935 2008-12-10 21:47:27Z mitza $
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 */
#ifndef Echo__h_
#define Echo__h_

#include "TestS.h"
#include "tao/PortableServer/PortableServer.h"

class Echo
  : public POA_Test::Echo
{
public:
  Echo(CORBA::ORB_ptr orb);

  virtual char * echo_operation(char const * the_input);
  virtual void shutdown(void);

private:
  CORBA::ORB_var orb_;
};

#endif /* Echo__h_ */
