// $Id: Collocation.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Collocation_Tester.h"
#include "tao/Strategies/advanced_resource.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try
    {
      Collocation_Test coll_test;

      coll_test.init (argc, argv);

      coll_test.run ();

      coll_test.shutdown ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("Uncaught exception: ");
    }

  return 0;
}
