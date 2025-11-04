/**
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: OwnershipQosPolicy.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_OWNERSHIPQOSPOLICY_H
#define DDS4CCM_OWNERSHIPQOSPOLICY_H

#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::OwnershipQosPolicy &ddsqos, const ::DDS_OwnershipQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS::OwnershipQosPolicyKind> (qos.kind);
}

inline void
operator<<= (::DDS_OwnershipQosPolicy &ddsqos, const ::DDS::OwnershipQosPolicy & qos)
{
  ddsqos.kind = static_cast < ::DDS_OwnershipQosPolicyKind> (qos.kind);
}

#endif /* DDS4CCM_OWNERSHIPQOSPOLICY_H */
