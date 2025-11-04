// $Id: Messenger_i.h 2179 2013-05-28 22:16:51Z mesnierp $

#ifndef __MESSENGER_I_H__
#define __MESSENGER_I_H__

#include "MessengerS.h"

class Messenger_i : public POA_SimpleMessenger::Messenger
{
public:
  Messenger_i (CORBA::ORB_ptr orb);
  virtual void send (void);

private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;
};

#endif
