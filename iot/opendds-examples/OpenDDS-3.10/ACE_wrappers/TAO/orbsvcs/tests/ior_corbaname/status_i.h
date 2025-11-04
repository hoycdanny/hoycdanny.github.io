//
// $Id: status_i.h 935 2008-12-10 21:47:27Z mitza $
//

#ifndef STATUS_I_H
#define STATUS_I_H

#include "corbanameS.h"

class corbaname_Status_i : public POA_corbaname::Status {
public:
  corbaname_Status_i (void);

  CORBA::Boolean print_status (void);

};

#endif /* STATUS_I_H */
