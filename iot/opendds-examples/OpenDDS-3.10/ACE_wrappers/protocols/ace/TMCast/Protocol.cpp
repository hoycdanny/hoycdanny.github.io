// $Id: Protocol.cpp 1861 2011-08-31 16:18:08Z mesnierp $
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>

#include "Protocol.hpp"

namespace ACE_TMCast
{
  namespace Protocol
  {
    /*
      namespace
      {
      char const* labels[] = {
      "NONE", "BEGIN", "COMMIT", "ABORT", "COMMITED", "ABORTED"};
      }

      std::string
      tslabel (Protocol::TransactionStatus s)
      {
      return labels[s];
      }

      std::ostream&
      operator << (std::ostream& o, Transaction const& t)
      {
      return o << "{" << t.id << "; " << tslabel (t.status) << "}";
      }
    */
  }
}
