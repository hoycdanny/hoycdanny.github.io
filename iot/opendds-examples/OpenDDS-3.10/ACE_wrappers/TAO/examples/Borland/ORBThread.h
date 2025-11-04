// $Id: ORBThread.h 1861 2011-08-31 16:18:08Z mesnierp $
//---------------------------------------------------------------------------
#ifndef ORBThreadH
#define ORBThreadH
//---------------------------------------------------------------------------
#include "tao/ORB.h"
//---------------------------------------------------------------------------
class PACKAGE TORBThread : public TThread
{
  // Class for running the orb in a separate thread.
public:
  // = Initialization and termination methods.
  __fastcall TORBThread (CORBA::ORB_ptr orb);
  // Constructor.

  __fastcall ~TORBThread ();
  // Destructor.

protected:
  void __fastcall Execute ();
  // Perform the thread's work.

private:
  CORBA::ORB_var orb_;
  // Reference to the orb.
};
//---------------------------------------------------------------------------
#endif
