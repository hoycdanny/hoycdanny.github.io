//
// $Id: Simple.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//
#include "Simple.h"

Simple::Simple (void)
{
}

void
Simple::destroy (void)
{
  PortableServer::POA_var poa = this->_default_POA ();

  PortableServer::ObjectId_var oid =
    poa->servant_to_id (this);

  poa->deactivate_object (oid.in ());
}
