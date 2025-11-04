// $Id: Client_i.cpp 2179 2013-05-28 22:16:51Z mesnierp $

#include "Client_i.h"

Client::~Client () {}

void Client::reply (const char * msg)
{
  this->reply_count_++;
  ACE_DEBUG ((LM_DEBUG, "(%P|%t) Client::reply -> %s\n", msg));
}
