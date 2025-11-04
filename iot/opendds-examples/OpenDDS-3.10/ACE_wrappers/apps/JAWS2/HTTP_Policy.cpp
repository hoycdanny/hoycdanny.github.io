// $Id: HTTP_Policy.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "HTTP_Policy.h"



HTTP_Policy::HTTP_Policy (JAWS_Concurrency_Base *concurrency)
  : concurrency_ (concurrency)
{
}

JAWS_Concurrency_Base *
HTTP_Policy::update (void *)
{
  /* for now, we always return the same concurrency strategy */
  return this->concurrency_;
}
