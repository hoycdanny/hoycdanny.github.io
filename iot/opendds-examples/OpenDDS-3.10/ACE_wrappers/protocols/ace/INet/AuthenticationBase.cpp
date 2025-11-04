// $Id: AuthenticationBase.cpp 2205 2013-06-20 17:12:10Z mesnierp $

#include "ace/INet/AuthenticationBase.h"

#if !defined (__ACE_INLINE__)
#include "ace/INet/AuthenticationBase.inl"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace INet
  {
    AuthenticationBase::~AuthenticationBase () {}

    AuthenticatorBase::~AuthenticatorBase () {}
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
