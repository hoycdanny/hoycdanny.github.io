//
// $Id: bogus_i.h 935 2008-12-10 21:47:27Z mitza $
//

#ifndef bogus_h
#define bogus_h
#include /**/ "ace/pre.h"

#include "bogusS.h"

class bogus
  : public virtual POA_Test::bogus
{
public:
  bogus ();
  virtual ~bogus ();

  virtual void noop (void);
};

#include /**/ "ace/post.h"
#endif //bogus_h
