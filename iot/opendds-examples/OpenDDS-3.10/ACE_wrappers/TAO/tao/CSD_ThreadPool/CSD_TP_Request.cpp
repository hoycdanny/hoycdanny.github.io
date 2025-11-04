// $Id: CSD_TP_Request.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "tao/CSD_ThreadPool/CSD_TP_Request.h"

#if !defined (__ACE_INLINE__)
# include "tao/CSD_ThreadPool/CSD_TP_Request.inl"
#endif /* ! __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO::CSD::TP_Request::~TP_Request()
{
}


void
TAO::CSD::TP_Request::prepare_for_queue_i()
{
  // Default implementation is to do nothing.  Subclasses can provide
  // their own implementation if needed.
}

TAO_END_VERSIONED_NAMESPACE_DECL
