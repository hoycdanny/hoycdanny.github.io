//
// $Id: MyInterfaceImpl.cpp 935 2008-12-10 21:47:27Z mitza $
//

#include "MyInterfaceImpl.h"

const char*
MyInterfaceImpl::my_string = "a string";

MyInterfaceImpl::MyInterfaceImpl (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}
CORBA::Boolean
MyInterfaceImpl::myMethod (const char* mystring)
{
  return mystring == my_string;
}

