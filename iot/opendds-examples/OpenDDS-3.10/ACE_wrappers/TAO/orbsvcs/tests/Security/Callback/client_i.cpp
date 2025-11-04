// $Id: client_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "ace/Log_Msg.h"
#include "client_i.h"

client_i::client_i (server_ptr s)
  : server_ (server::_duplicate (s))
{
}

client_i::~client_i (void)
{
}

void
client_i::test_reply (const char *msg)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%N) message received was ")
             ACE_TEXT("(%s)\n"),
             msg));
}
