// $Id: client.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "PP_Test_Client.h"
#include "tao/Timeprobe.h"

// This function runs the client test.

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  PP_Test_Client pp_test_client;

  ACE_DEBUG ((LM_DEBUG,
              "\n\tPluggable_Test: client\n\n"));

  if (pp_test_client.init (argc, argv) == -1)
    return 1;

  int retval = pp_test_client.run ();

  ACE_TIMEPROBE_PRINT;

  return retval;
}
