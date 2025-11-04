// $Id: typeconsistencyenforcement_qos_test.cpp 2179 2013-05-28 22:16:51Z mesnierp $

#include "typeconsistencyenforcement_qos_test.h"

#if defined (RTI_DDS_VERSION_MAJOR) && (RTI_DDS_VERSION_MAJOR >= 5)

TypeConsistencyEnforcementPolicyPolicyTest::TypeConsistencyEnforcementPolicyPolicyTest ()
{
}

bool
TypeConsistencyEnforcementPolicyPolicyTest::check (const ::DDS_TypeConsistencyEnforcementQosPolicy & dds_qos,
                              const ::DDS::TypeConsistencyEnforcementQosPolicy & qos)
{
  return dds_qos.kind == static_cast <DDS_TypeConsistencyKind> (qos.kind);
}

#endif
