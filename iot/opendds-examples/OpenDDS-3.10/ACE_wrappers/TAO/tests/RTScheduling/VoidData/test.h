//$Id: test.h 935 2008-12-10 21:47:27Z mitza $

#include "ace/Log_Msg.h"

class test_impl :public test
{
 public:
  virtual void bar (CORBA::VoidData something)

  {
    ACE_DEBUG ((LM_DEBUG,
                "Void Data Passed to method %d\n",
                *(int*)something));
  }
};

