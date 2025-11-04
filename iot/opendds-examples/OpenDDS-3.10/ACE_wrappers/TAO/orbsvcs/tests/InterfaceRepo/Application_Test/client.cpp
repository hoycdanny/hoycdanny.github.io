// -*- C++ -*-
// $Id: client.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "ifr_dii_client.h"

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  IFR_DII_Client client;

  try
    {
      if (client.init (argc,
                       argv)
           == -1)
        {
          return 1;
        }
      else
        {
           int status = client.run ();

           if (status == -1)
           {
              return 1;
           }
        }
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Client Exception");
      return -1;
    }

  return 0;
}
