// -*- C++ -*-
// $Id: client.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Latency_Query_Client.h"

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  Latency_Query_Client client;

  int retval = client.init (argc, argv);

  if (retval == -1)
    {
      return 1;
    }

  retval = client.run ();

  return retval;
}
