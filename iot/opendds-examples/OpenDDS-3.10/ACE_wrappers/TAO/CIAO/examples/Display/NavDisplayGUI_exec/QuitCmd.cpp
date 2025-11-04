// $Id: QuitCmd.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "QuitCmd.h"
#include "RootPanel.h"

QuitCmd::QuitCmd()
{
}

QuitCmd *
QuitCmd::create(RootPanel *form)
{
  QuitCmd *cmd = new QuitCmd ();
  cmd->form_ = form;
  return cmd;
}

int
QuitCmd::execute (void * /* context */)
{
  return form_->close ();
}
