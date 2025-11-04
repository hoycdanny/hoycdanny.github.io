// -*- C++ -*-
// $Id: main.cpp 935 2008-12-10 21:47:27Z mitza $

#include "FactoryDriver.h"
#include "orbsvcs/CosEvent/CEC_Default_Factory.h"

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  TAO_CEC_Default_Factory::init_svcs ();
  FactoryDriver driver;
  driver.start (argc, argv);
  return 0;
}
