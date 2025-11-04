/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Identity_i.cpp
 *
 *  $Id: Identity_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  Implements the interface in Identity.idl.
 *
 *
 *  @author Marina Spivak <marina@cs.wustl.edu>
 */
//=============================================================================

#include "Identity_i.h"

Identity_i::Identity_i (const char *name)
  : name_ (name)
{
}

Identity_i::~Identity_i (void)
{
}

void
Identity_i::get_name (CORBA::String_out name
 )
{
  name = this->name_.in ();
}
