// -*- C++ -*-
// $Id: client.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Admin_Client.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  Admin_Client admin_client;

  int retval = admin_client.init (argc, argv);

  if (retval == -1)
    {
      return 1;
    }

  return admin_client.run ();
}
