// $Id: test.cpp 2465 2015-02-18 17:08:32Z mesnierp $

#include "tao/Stub.h"
#include "tao/Profile.h"
#include "tao/Endpoint.h"
#include "tao/IIOP_Endpoint.h"

const ACE_TCHAR *ior = ACE_TEXT ("corbaloc::localhost:12345/objname");

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  int ret = 1;
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
      CORBA::Object_var tmp = orb->string_to_object(ior);
      TAO_IIOP_Endpoint *ep =
        dynamic_cast<TAO_IIOP_Endpoint *> (tmp->_stubobj ()->profile_in_use ()->endpoint ());
      const ACE_INET_Addr addr = ep->object_addr ();
      int test =
        TAO_IIOP_Endpoint::try_ipv4_first_ ? AF_INET : AF_INET6;
      ret = addr.get_type () == test ? 0 : 1;

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("Addr expected %d got %d\n"),
                  test, addr.get_type () ));

      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Exception caught:");
      return 1;
    }

  return ret;
}
