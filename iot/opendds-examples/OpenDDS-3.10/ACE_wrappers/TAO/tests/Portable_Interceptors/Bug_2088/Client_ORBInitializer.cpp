// -*- C++ -*-
// $Id: Client_ORBInitializer.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Client_ORBInitializer.h"

Client_ORBInitializer::Client_ORBInitializer (void) :
  pre_init_called (false),
  post_init_called (false)
{
}

void
Client_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr)
{
  pre_init_called = true;

  throw CORBA::NO_MEMORY ();
}

void
Client_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr)
{
  post_init_called = true;

  throw CORBA::NO_MEMORY ();
}

