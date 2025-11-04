// $Id: test_spipe_connector.cpp 1861 2011-08-31 16:18:08Z mesnierp $

// ACE_SPIPE Client.

#include "SPIPE-connector.h"



int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  // Perform Service_Config initializations
  ACE_Service_Config daemon (argv[0]);

  IPC_Client peer_connector;

  if (peer_connector.init (argc, argv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("init")), -1);

  return peer_connector.svc ();
}
