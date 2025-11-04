//
// $Id: status_i.cpp 935 2008-12-10 21:47:27Z mitza $
//

#include "status_i.h"

corbaname_Status_i::corbaname_Status_i (void)
{
  // Constructor
}

CORBA::Boolean
corbaname_Status_i::print_status (void)
{
  // If the client makes a succesful request, return a true value
  // indicating that it has successfully reached the server.
  return 0;
}
