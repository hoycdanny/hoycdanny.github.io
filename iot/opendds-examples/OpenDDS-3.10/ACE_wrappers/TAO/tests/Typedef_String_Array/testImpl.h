// $Id: testImpl.h 935 2008-12-10 21:47:27Z mitza $

#include "testS.h"

class TestImpl: public POA_SimpleStrings
{
public:
  TestImpl(CORBA::ORB_ptr orb);

  virtual void get_strings (ArrayOfString_out strings);

private:
  CORBA::ORB_var orb_;
};
