// $Id: NM_Launcher.cpp 2179 2013-05-28 22:16:51Z mesnierp $

#include "NM_Launcher.h"

namespace DAnCE
{
  NM_Launcher::NM_Launcher (CORBA::ORB_ptr orb,
                            __Base::Manager_ptr manager)
    : __Base (orb, manager)
  {
  }

  NM_Launcher::~NM_Launcher (void)
  {
  }
}
