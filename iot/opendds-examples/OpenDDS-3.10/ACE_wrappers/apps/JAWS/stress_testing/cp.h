// $Id: cp.h 14 2007-02-01 15:49:12Z mitza $

#include "util.h"
#include "stats.h"

class Client_Parameters {
public:
  Client_Parameters(int);
  URL *url;
  static Stats *stats;
  static int tcp_nodelay;
  static int sockbufsiz;
  int id;
};
