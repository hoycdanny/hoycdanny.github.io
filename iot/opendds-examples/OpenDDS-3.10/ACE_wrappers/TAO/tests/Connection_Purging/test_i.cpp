//
// $Id: test_i.cpp 935 2008-12-10 21:47:27Z mitza $
//
#include "test_i.h"

void
test_i::send_stuff (const char* string)
{
  ACE_DEBUG ((LM_DEBUG, "TAO (%P|%t) - %C\n", string));
}

