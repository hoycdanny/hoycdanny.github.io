// $Id: server.cpp 2646 2015-08-28 00:38:05Z mesnierp $

#include "simple_test_i.h"
#include "ace/Log_Msg.h"
#include "tao/ORB_Core.h"
#include "tao/Resource_Factory.h"
#include "tao/IORTable/IORTable.h"
#include "tao/PortableServer/PortableServer.h"

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  try
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);
      CORBA::Object_var obj = orb->resolve_initial_references ("RootPOA");
      PortableServer::POA_var poa = PortableServer::POA::_narrow (obj.in ());

      if (CORBA::is_nil (poa.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Panic: nil RootPOA\n"),
                          1);

      obj = orb->resolve_initial_references("IORTable");
      IORTable::Table_var table = IORTable::Table::_narrow (obj.in ());

      PortableServer::ServantBase_var impl;
      ACE_NEW_RETURN (impl, Simple_Test_i (orb.in ()), 1);
      PortableServer::ObjectId_var id = poa->activate_object (impl.in ());
      obj = poa->id_to_reference (id.in ());
      CORBA::String_var testIOR = orb->object_to_string (obj.in ());

      if (!orb->orb_core ()->resource_factory ()->refresh_IORTable ())
        {
          table->refresh (true);
        }
      table->bind ("Refresher", testIOR.in ());
      PortableServer::POAManager_var pm = poa->the_POAManager ();
      pm->activate ();
      orb->run ();
      ACE_DEBUG ((LM_DEBUG, "Server - event loop finished\n"));
      poa->destroy (1, 1);
      orb->destroy ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Server - Exception caught:");
      return 1;
    }

  return 0;
}
