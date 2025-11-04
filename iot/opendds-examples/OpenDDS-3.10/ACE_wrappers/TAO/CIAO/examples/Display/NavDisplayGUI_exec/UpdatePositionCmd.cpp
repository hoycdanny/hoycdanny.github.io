// $Id: UpdatePositionCmd.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "RootPanel.h"
#include "UpdatePositionCmd.h"
#include <QtGui/qlcdnumber.h>
#include "NavUnit.h"

UpdatePositionCmd::UpdatePositionCmd()
{
}

UpdatePositionCmd *
UpdatePositionCmd::create(
  RootPanel *form, NavUnit *unit)
{
  UpdatePositionCmd *cmd = new UpdatePositionCmd();
  cmd->form_ = form;
  cmd->unit_ = unit;
  return cmd;
}

int
UpdatePositionCmd::execute (void * /* context */)
{
  this->form_->updateUnit (this->unit_);
  return 0;
}
