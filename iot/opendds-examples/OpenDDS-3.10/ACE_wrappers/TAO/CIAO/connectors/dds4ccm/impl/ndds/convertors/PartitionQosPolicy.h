/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: PartitionQosPolicy.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_PARTITIONQOSPOLICY_H
#define DDS4CCM_PARTITIONQOSPOLICY_H

#include "StringSeq.h"

#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::PartitionQosPolicy &ddsqos, const ::DDS_PartitionQosPolicy & qos)
{
  ddsqos.name <<= qos.name;
}

inline void
operator<<= (::DDS_PartitionQosPolicy &ddsqos, const ::DDS::PartitionQosPolicy & qos)
{
  ddsqos.name <<= qos.name;
}

#endif /* DDS4CCM_PARTITIONQOSPOLICY_H */
