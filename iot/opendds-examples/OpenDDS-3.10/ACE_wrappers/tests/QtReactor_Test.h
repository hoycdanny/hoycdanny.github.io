/* -*- C++ -*- */
// $Id: QtReactor_Test.h 1861 2011-08-31 16:18:08Z mesnierp $
#ifndef QTREACTOR_TEST_H
#define QTREACTOR_TEST_H

#include <QtGui/qapplication.h>
#include <QtCore/qtimer.h>

class QTestApplication: public QApplication
{
  Q_OBJECT
public:
  typedef QApplication inherited;
public:
  QTestApplication( int argc, char *argv[] );
  virtual void exec( int msec = 0 );
public slots:
  virtual void finishTest(); //!< slot to finish the test, connected to finishTimer_
private:
  QTimer finishTimer_; //!< timer to finish the test
};

#endif /*QTREACTOR_TEST_H*/
