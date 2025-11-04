// -*- C++ -*-
//
// $Id: FTP_URL.inl 2205 2013-06-20 17:12:10Z mesnierp $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace FTP
  {

    ACE_INLINE
    const ACE_CString& URL::get_scheme () const
      {
        return protocol ();
      }

    ACE_INLINE
    u_short URL::default_port () const
      {
        return FTP_PORT;
      }

  }
}

ACE_END_VERSIONED_NAMESPACE_DECL
