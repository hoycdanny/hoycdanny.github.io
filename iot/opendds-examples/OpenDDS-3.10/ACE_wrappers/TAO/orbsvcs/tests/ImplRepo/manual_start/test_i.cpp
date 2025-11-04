/* -*- C++ -*- $Id: test_i.cpp 2390 2014-10-23 22:23:27Z mesnierp $ */

#include "test_i.h"
#include "ace/Log_Msg.h"

Test_i::Test_i (void)
{
}

Test_i::~Test_i ()
{
}

void
Test_i::contact (void)
{
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("(%P|%t) Server contacted\n")));
}
