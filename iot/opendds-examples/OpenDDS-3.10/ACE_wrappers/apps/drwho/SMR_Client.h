/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    SMR_Client.h
 *
 *  $Id: SMR_Client.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef _SMR_CLIENT_H
#define _SMR_CLIENT_H

#include "SM_Client.h"

class SMR_Client : public SM_Client
{
public:
  SMR_Client (short port_number);
  virtual ~SMR_Client (void);
};

#endif /* _SMR_CLIENT_H */
