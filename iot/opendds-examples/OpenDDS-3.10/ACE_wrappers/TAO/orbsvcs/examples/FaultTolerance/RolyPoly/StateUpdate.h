// file      : RolyPoly/StateUpdate.h
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: StateUpdate.h 14 2007-02-01 15:49:12Z mitza $

#ifndef STATE_UPDATE_H
#define STATE_UPDATE_H

#include "tao/corba.h"

class Checkpointable
{
public:
  virtual
  ~Checkpointable ();

  virtual CORBA::Any*
  get_state ();

  static void
  associate_state (CORBA::ORB_ptr orb, CORBA::Any const& state);

  virtual void
  set_state (CORBA::Any const& state) = 0;
};


#endif // STATE_UPDATE_H
