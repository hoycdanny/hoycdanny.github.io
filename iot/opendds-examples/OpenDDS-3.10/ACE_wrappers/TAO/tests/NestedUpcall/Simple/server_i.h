// $Id: server_i.h 935 2008-12-10 21:47:27Z mitza $

#include "testS.h"

class server_i : public POA_server
{
public:
  server_i (int quiet,
            CORBA::ORB_ptr orb);

  void ping (CORBA::UShort time_to_live);

  void start (client_ptr c,
              CORBA::UShort time_to_live);

  void shutdown (void);

private:
  int quiet_;
  // Be quiet.

  client_var client_;
  // Pointer to server.

  CORBA::ORB_var orb_;
  // Pointer to orb.
};
