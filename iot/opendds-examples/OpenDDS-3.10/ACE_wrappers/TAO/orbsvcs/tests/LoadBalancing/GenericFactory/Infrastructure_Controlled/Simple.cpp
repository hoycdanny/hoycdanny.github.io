// $Id: Simple.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "Simple.h"

Simple::Simple (void)
{
}

char *
Simple::get_string (void)
{
  return CORBA::string_dup ("TAO Load Balancing Works!");
}
