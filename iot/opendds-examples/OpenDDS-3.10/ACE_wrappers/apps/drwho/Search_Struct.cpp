// $Id: Search_Struct.cpp 14 2007-02-01 15:49:12Z mitza $

#include "Options.h"
#include "Search_Struct.h"
#include "ace/Log_Msg.h"

Search_Struct::~Search_Struct (void)
{
  if (Options::get_opt (Options::DEBUGGING))
    ACE_DEBUG ((LM_DEBUG,
                "disposing Search_Struct\n"));
}

Search_Struct::Search_Struct (void)
  : count_ (0)
{}

int
Search_Struct::n_elems (void)
{
  return this->count_;
}

