// $Id: DemoObservable.java 1861 2011-08-31 16:18:08Z mesnierp $
//
// = FILENAME
//    DemoObservable.java
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// = DESCRIPTION
//   This class servers as the core class of the simulation demo
//
// ============================================================================



public abstract class DemoObservable extends java.util.Observable {

  public abstract int getProperty ();
}
