// -*- C++ -*-
// $Id: main.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "RedGreen_Test.h"

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  ACE_High_Res_Timer::calibrate ();

  RedGreen_Test client;

  client.parse_args (argc, argv);

  try
    {
      client.init (argc, argv); //Init the Client

      client.run ();
    }
  catch (const CORBA::Exception& se)
    {
      se._tao_print_exception ("Error: ");
      return 1;
    }

  return 0;
}
