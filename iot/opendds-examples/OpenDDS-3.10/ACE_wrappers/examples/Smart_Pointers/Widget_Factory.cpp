/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Widget_Factory.cpp
 *
 *  $Id: Widget_Factory.cpp 14 2007-02-01 15:49:12Z mitza $
 *
 *  @author Christopher Kohlhoff <chris@kohlhoff.com>
 */
//=============================================================================

#include "Widget_Factory.h"
#include "Widget_Impl.h"

Widget *Widget_Factory::create_widget (void)
{
  return new Widget_Impl;
}
