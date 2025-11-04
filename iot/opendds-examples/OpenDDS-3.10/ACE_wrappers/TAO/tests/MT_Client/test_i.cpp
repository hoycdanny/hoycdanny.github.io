// $Id: test_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "test_i.h"

#if !defined(__ACE_INLINE__)
#include "test_i.inl"
#endif /* __ACE_INLINE__ */

void
Simple_Server_i::test_method (void)
{
}

void
Simple_Server_i::shutdown (void)
{
  this->orb_->shutdown (0);
}
