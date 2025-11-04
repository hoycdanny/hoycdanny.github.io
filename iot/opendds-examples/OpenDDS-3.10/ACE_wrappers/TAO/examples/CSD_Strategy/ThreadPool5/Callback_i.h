// $Id: Callback_i.h 935 2008-12-10 21:47:27Z mitza $
#ifndef CALLBACK_I_H
#define CALLBACK_I_H

#include "CallbackS.h"


class Callback_i : public virtual POA_Callback
{
  public:

    Callback_i();

    virtual ~Callback_i();

    virtual void test_method (
    );
};


#endif
