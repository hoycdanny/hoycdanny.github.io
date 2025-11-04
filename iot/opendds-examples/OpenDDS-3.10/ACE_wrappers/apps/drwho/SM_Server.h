/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    SM_Server.h
 *
 *  $Id: SM_Server.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef _SM_SERVER_H
#define _SM_SERVER_H

#include "PM_Server.h"
#include "CM_Server.h"
#include "Select_Manager.h"

class SM_Server : public Select_Manager, public CM_Server
{
public:
  SM_Server (void);
  virtual ~SM_Server (void);
  virtual int mux (char *packet, int &packet_length);
  virtual int demux (char *packet, int &packet_length);

private:
  PM_Server *pm_server;
};

#endif /* _SM_SERVER_H */
