// $Id: QuitCmd.h 935 2008-12-10 21:47:27Z mitza $

#ifndef __QUITCMD_H
#define __QUITCMD_H

#include "Command.h"

class RootPanel;

class QuitCmd : public CommandBase
{
public:
  static QuitCmd *create(RootPanel *form);

public:
  virtual int execute(void *context = 0);

protected:
  QuitCmd();

  RootPanel *form_;
};


#endif // __QUITCMD_H
