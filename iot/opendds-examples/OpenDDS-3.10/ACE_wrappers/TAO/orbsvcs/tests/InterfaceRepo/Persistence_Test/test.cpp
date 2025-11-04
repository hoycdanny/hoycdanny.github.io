// -*- C++ -*-
// $Id: test.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Ptest.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  Ptest ptest;

  int retval = ptest.init (argc, argv);

  if (retval == -1)
    return 1;

  retval = ptest.run ();

  return retval;
}
