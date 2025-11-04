// $Id: client.cpp 2655 2015-08-31 20:50:42Z mesnierp $

#include "simple_testC.h"
#include "ace/Get_Opt.h"
#include "ace/SString.h"

ACE_CString clstr("corbaloc:iiop:1.2@");
ACE_CString addr ("localhost");
ACE_CString port ("12345");
ACE_CString clend("/Refresher");

int
parse_args (int argc, ACE_TCHAR *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("a:p:"));
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'a':
        addr.set (ACE_TEXT_ALWAYS_CHAR (get_opts.opt_arg ()));
        break;

      case 'p':
        port.set (ACE_TEXT_ALWAYS_CHAR (get_opts.opt_arg ()));
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("usage:  %C ")
                           ACE_TEXT ("-a <server host ip>")
                           ACE_TEXT ("-p <server port>")
                           ACE_TEXT ("\n"),
                           argv [0]),
                          -1);
      }
  // Indicates successful parsing of the command line
  return 0;
}

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

      if (parse_args (argc, argv) != 0)
        return 1;

      clstr += addr + ":" + port + clend;
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("resolve a remote IORTable entry using %s\n"),
                  clstr.c_str ()));
      try
        {
          CORBA::Object_var clientObj = orb->string_to_object (clstr.c_str ());

          simple::SimpleTest_T_var simpleTestClient =
            simple::SimpleTest_T::_narrow (clientObj.in ());

          if (CORBA::is_nil (simpleTestClient.in ()))
            {
              ACE_ERROR ((LM_ERROR,
                          ACE_TEXT ("Simple client is nil!\n")));
              return 1;
            }

          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("We narrowed the object, now let's invoke it!\n")));

          simpleTestClient->shutdown ();
        }
      catch(const CORBA::OBJ_ADAPTER &objAdapter)
        {
          objAdapter._tao_print_exception (ACE_TEXT ("CAUGHT OBJ_ADAPTER!!!"));
        }
      catch(const CORBA::OBJECT_NOT_EXIST &objNE)
        {
          objNE._tao_print_exception (ACE_TEXT ("CAUGHT OBJECT NOT EXIST!!!"));
        }

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("Leaving!\n")));
    }
  catch (const CORBA::Exception &ex)
    {
      ex._tao_print_exception (ACE_TEXT ("CAUGHT EXCEPTION: "));
      return -1;
    }

  return 0;
}
