// $Id: pch.h 14 2007-02-01 15:49:12Z mitza $
// pch.h

#ifndef i_pch_h
#define i_pch_h

#include "ace/config-all.h"
#include "wx/wxprec.h"

#ifdef WX_PRECOMP
#include "tao/corba.h"
#endif

#ifdef __BORLANDC__
    #pragma hdrstop
#endif
#ifndef WX_PRECOMP
    #include "wx/wx.h"
    #include "tao/corba.h"
#endif

#endif
