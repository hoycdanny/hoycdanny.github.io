/* -*- C++ -*- $Id: Test_i.cpp 2244 2014-02-04 16:43:12Z mesnierp $ */

#include "Test_i.h"

CORBA::Short
Test_i::get_server_num (void)
{
  return 1;
}

void
Test_i::terminate (void)
{
  exit (0);
}


