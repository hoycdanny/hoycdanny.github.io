// $Id: client_i.h 935 2008-12-10 21:47:27Z mitza $

#include "testS.h"

class client_i : public POA_client
{
public:
  client_i (int quiet,
            server_ptr s);
  // Constructor.

  void ping (CORBA::UShort time_to_live);

private:
  int quiet_;
  // Be quiet.

  server_var server_;
  // Pointer to server.
};
