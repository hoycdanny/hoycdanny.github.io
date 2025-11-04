/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: DurabilityQosPolicy.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_DURABILITYQOSPOLICY_H
#define DDS4CCM_DURABILITYQOSPOLICY_H

#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::DurabilityQosPolicy &ddsqos, const ::DDS_DurabilityQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS::DurabilityQosPolicyKind> (qos.kind);
}

inline void
operator<<= (::DDS_DurabilityQosPolicy &ddsqos, const ::DDS::DurabilityQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS_DurabilityQosPolicyKind> (qos.kind);
}

#endif /* DDS4CCM_DURABILITYQOSPOLICY_H */
