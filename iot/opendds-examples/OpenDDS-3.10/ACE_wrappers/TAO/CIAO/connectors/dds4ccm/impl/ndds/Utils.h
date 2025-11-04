/**
 * @file Utils.h
 * @author Marcel Smit (msmit@remedy.nl)
 *
 * $Id: Utils.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Misc utility classes for NDDS.
 */

#ifndef NDDS_UTILS_H_
#define NDDS_UTILS_H_

#include "ace/String_Base.h"

namespace CIAO
{
  namespace NDDS
  {
    char * get_library_name (const char * qos_profile);
    char * get_profile_name (const char * qos_profile);
  }
}

#endif /* NDDS_UTILS_H_ */
