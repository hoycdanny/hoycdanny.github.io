//$Id: server_main.cpp 1861 2011-08-31 16:18:08Z mesnierp $
#include "TestServer.h"

#include <ace/streams.h>

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
  {
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

    TestServer server (orb.in(), argc, argv);
    server.run();

    orb->destroy();
    return 0;
  }
  catch (CORBA::Exception& ex)
  {
    cerr << "CORBA error: " << ex << endl;
  }
  return 1;
}
