/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: Duration_t.h 2179 2013-05-28 22:16:51Z mesnierp $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_DURATION_T_H_
#define DDS4CCM_DURATION_T_H_

#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::Duration_t &ddsduration, const ::DDS_Duration_t & duration)
{
  ddsduration.sec = duration.sec;
  ddsduration.nanosec = duration.nanosec;
}

inline void
operator<<= (::DDS_Duration_t &ddsduration, const ::DDS::Duration_t & duration)
{
  ddsduration.sec = duration.sec;
  ddsduration.nanosec = duration.nanosec;
}

#endif /* DDS4CCM_DURATION_T_H_ */

