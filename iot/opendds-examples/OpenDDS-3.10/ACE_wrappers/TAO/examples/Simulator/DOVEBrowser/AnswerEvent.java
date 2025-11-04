// $Id: AnswerEvent.java 1861 2011-08-31 16:18:08Z mesnierp $
//
// = FILENAME
//    AnswerEvent.java
//
// = AUTHOR
//    Michael Kircher (mk1@cs.wustl.edu)
//
// = DESCRIPTION
//   Event definition for the Dialog for selecting Observables.
//
// ============================================================================

public class AnswerEvent extends java.util.EventObject {

  protected String selected_;

  public AnswerEvent (Object source, String selected) {
    super (source);
    this.selected_ = selected;
  }
}

