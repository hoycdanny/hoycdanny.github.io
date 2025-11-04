/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: UserDataQosPolicy.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_USERDATAQOSPOLICY_H
#define DDS4CCM_USERDATAQOSPOLICY_H

#include "OctetSeq.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::UserDataQosPolicy &ddsqos, const ::DDS_UserDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

inline void
operator<<= (::DDS_UserDataQosPolicy &ddsqos, const ::DDS::UserDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

#endif /* DDS4CCM_USERDATAQOSPOLICY_H */
