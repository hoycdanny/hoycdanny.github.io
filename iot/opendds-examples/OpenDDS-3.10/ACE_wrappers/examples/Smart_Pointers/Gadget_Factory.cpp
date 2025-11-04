/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Gadget_Factory.cpp
 *
 *  $Id: Gadget_Factory.cpp 14 2007-02-01 15:49:12Z mitza $
 *
 *  @author Christopher Kohlhoff <chris@kohlhoff.com>
 */
//=============================================================================

#include "Gadget_Factory.h"
#include "Gadget_Impl.h"

Gadget_var Gadget_Factory::create_gadget (void)
{
  return Gadget_var (new Gadget_Impl);
}
