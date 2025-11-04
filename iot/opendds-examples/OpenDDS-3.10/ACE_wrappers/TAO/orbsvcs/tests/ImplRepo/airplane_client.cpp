// $Id: airplane_client.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "airplane_client_i.h"

#include "ace/Log_Msg.h"

// This function runs the test.

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  Airplane_Client_i client;

  ACE_DEBUG ((LM_DEBUG, "\n\tPaper Airplane Client\n\n"));

  if (client.init (argc, argv) == -1)
    return 1;
  else
    return client.run ();
}
