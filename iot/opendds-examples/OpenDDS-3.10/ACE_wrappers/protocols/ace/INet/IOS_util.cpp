// $Id: IOS_util.cpp 2205 2013-06-20 17:12:10Z mesnierp $

#include "ace/INet/IOS_util.h"



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace IOS
  {

    std::ostream Null::out_stream_ (0);
    std::istream Null::in_stream_ (0);

  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
