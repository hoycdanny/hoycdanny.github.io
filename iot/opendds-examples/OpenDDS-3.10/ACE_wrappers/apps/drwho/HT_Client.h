/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    HT_Client.h
 *
 *  $Id: HT_Client.h 1861 2011-08-31 16:18:08Z mesnierp $
 *
 *  @author Douglas C. Schmidt
 */
//=============================================================================


#ifndef _HT_CLIENT_H
#define _HT_CLIENT_H

#include "Hash_Table.h"

/**
 * @class HT_Client
 *
 * @brief Provides the client's hash table abstraction.
 */
class HT_Client : public Hash_Table
{
public:
  virtual Protocol_Record *insert (const char *key_name,
                                   int max_len = MAXUSERIDNAMELEN);
};

#endif /* _HT_CLIENT_H */
