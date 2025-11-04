/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    SMR_Server.h
 *
 *  $Id: SMR_Server.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef _SMR_SERVER_H
#define _SMR_SERVER_H

#include "SM_Server.h"

class SMR_Server : public SM_Server
{
public:
  SMR_Server (short port_number);
  ~SMR_Server (void);
};

#endif /* _SMR_SERVER_H */
