//
// $Id: HelloWorld.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//

#include "HelloWorld.h"

HelloWorld::HelloWorld (void)
{
}

char *
HelloWorld::get_string (void)
{
  return CORBA::string_dup ("TAO Any Implementation Works!");
}
