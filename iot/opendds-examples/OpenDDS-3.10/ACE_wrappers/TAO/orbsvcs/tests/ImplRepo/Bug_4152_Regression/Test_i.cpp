/* -*- C++ -*- $Id: Test_i.cpp 2234 2014-01-07 23:02:51Z mesnierp $ */

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


