// $Id: Time_Service_Server.cpp 2179 2013-05-28 22:16:51Z mesnierp $

#include "orbsvcs/Log_Macros.h"
#include "Server_i.h"
#include "ace/OS_main.h"



// This is the main driver program for the Time Service server.

int
ACE_TMAIN (int argc, ACE_TCHAR* argv[])
{
  Server_i server;

  ORBSVCS_DEBUG ((LM_DEBUG,
              "[SERVER] Process/Thread Id : (%P/%t) Time Service server\n"));

  try
    {
      int r = server.init (argc, argv);

      if (r == -1)
        return 1;
      else
        {
          server.run ();
        }
    }
  catch (const CORBA::SystemException& sysex)
    {
      sysex._tao_print_exception ("System Exception");
      return -1;
    }
  catch (const CORBA::UserException& userex)
    {
      userex._tao_print_exception ("User Exception");
      return -1;
    }

  return 0;
}
