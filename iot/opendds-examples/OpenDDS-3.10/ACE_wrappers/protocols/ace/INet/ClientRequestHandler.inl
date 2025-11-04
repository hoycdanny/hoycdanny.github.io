// -*- C++ -*-
//
// $Id: ClientRequestHandler.inl 2205 2013-06-20 17:12:10Z mesnierp $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace INet
  {

    ACE_INLINE
    const ACE_CString& ClientINetRequestHandler::INetConnectionKey::host () const
      {
        return this->host_;
      }

    ACE_INLINE
    u_short ClientINetRequestHandler::INetConnectionKey::port () const
      {
        return this->port_;
      }

  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
