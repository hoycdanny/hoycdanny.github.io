// -*- C++ -*-
// $Id: test_i.h 935 2008-12-10 21:47:27Z mitza $

#include "testS.h"

// Must include this header file and link to TAO_IFR_Client.lib
// to dynamically load this necessary library.
#include "tao/IFR_Client/IFR_Client_Adapter_Impl.h"

class inventory_i : public POA_warehouse::inventory
{
public:
  CORBA::Boolean getCDinfo (const char * artist,
                            char *& title,
                            CORBA::Float_out price);
};

