// $Id: DLL_Test_Parent.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "DLL_Test_Parent.h"
#include "ace/Log_Msg.h"

Parent::~Parent (void)
{
}

void
Parent::test (void)
{
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("parent called\n")));
}
