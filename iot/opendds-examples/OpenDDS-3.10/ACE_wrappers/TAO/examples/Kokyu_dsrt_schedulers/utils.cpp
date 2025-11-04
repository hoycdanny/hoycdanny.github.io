//$Id: utils.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "utils.h"
#include "Kokyu/Kokyu.h"
#include "ace/Lock_Adapter_T.h"
#include "ace/OS_NS_string.h"

void guid_copy( Kokyu::GuidType& lhs, const RTScheduling::Current::IdType& rhs)
{
  lhs.length(rhs.length ());
  ACE_OS::memcpy(lhs.get_buffer (),
                 rhs.get_buffer (),
                 rhs.length ());
}

void guid_copy( RTScheduling::Current::IdType& lhs, const Kokyu::GuidType& rhs)
{
  lhs.length(rhs.length ());
  ACE_OS::memcpy(lhs.get_buffer (),
                 rhs.get_buffer (),
                 rhs.length ());
}

