//
// $Id: Receiver_i.cpp 1861 2011-08-31 16:18:08Z mesnierp $
//
#include "Receiver_i.h"

Receiver_i::Receiver_i (void)
  :  message_count_ (0)
  ,  byte_count_ (0)
{
}


void
Receiver_i::receive_payload (const Receiver::Payload &payload)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, this->mutex_);
  this->message_count_++;
  this->byte_count_ += payload.length ();
}

CORBA::Long
Receiver_i::get_event_count (void)
{
  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->mutex_, 0);
  return this->message_count_;
}
