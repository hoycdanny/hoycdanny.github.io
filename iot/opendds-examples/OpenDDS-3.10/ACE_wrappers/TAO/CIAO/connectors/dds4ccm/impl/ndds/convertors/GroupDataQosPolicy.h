/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: GroupDataQosPolicy.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_GROUPDATAQOSPOLICY_H
#define DDS4CCM_GROUPDATAQOSPOLICY_H

#include "OctetSeq.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::GroupDataQosPolicy &ddsqos, const ::DDS_GroupDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

inline void
operator<<= (::DDS_GroupDataQosPolicy &ddsqos, const ::DDS::GroupDataQosPolicy & qos)
{
  ddsqos.value <<= qos.value;
}

#endif /* DDS4CCM_GROUPDATAQOSPOLICY_H */
