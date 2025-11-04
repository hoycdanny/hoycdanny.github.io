#ifndef CHILDSERVANT_H
#define CHILDSERVANT_H

// $Id: ChildServant.h 935 2008-12-10 21:47:27Z mitza $

#include "ChildS.h"

class ChildServant
  : public virtual POA_Child
{
 public:
   ChildServant (CORBA::ORB_ptr orb);
   virtual void parentMethod ();
   virtual void childMethod ();
   virtual void shutdown ();

 private:
   CORBA::ORB_var orb_;
};

#endif
