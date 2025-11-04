// $Id: main.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "TLS_Client.h"
#include "ace/OS_main.h"

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  TLS_Client client; // Telecom Log Service Client

  try
    {
      client.init (argc, argv); //Init the Client

      client.run_tests (); //Init the Client

    }
  catch (const CORBA::UserException& ue)
    {
      ue._tao_print_exception ("TLS_Client user error: ");
      return 1;
    }
  catch (const CORBA::SystemException& se)
    {
      se._tao_print_exception ("TLS_Client system error: ");
      return 1;
    }

  return 0;
}
