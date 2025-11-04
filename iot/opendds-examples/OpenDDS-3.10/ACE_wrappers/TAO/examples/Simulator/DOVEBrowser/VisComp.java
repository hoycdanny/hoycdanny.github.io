// $Id: VisComp.java 1861 2011-08-31 16:18:08Z mesnierp $
//
// = FILENAME
//    VisComp.java
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// = DESCRIPTION
//   This is the interface for Java Beans.
//
// ============================================================================


public interface VisComp extends java.util.Observer {

  public void setName (String title);
  public int getProperty ();
}
