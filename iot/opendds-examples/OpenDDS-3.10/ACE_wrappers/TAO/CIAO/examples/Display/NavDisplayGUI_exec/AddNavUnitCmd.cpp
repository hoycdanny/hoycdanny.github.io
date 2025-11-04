// $Id: AddNavUnitCmd.cpp 1861 2011-08-31 16:18:08Z mesnierp $

#include "AddNavUnitCmd.h"
#include "RootPanel.h"
#include "NavUnit.h"

AddNavUnitCmd::AddNavUnitCmd()
{
}

AddNavUnitCmd *
AddNavUnitCmd::create(RootPanel *form, NavUnit *unit)
{
  AddNavUnitCmd *cmd = new AddNavUnitCmd();
  cmd->form_ = form;
  cmd->unit_ = unit;
  return cmd;
}

int
AddNavUnitCmd::execute(void * /* context */)
{
  this->form_->addUnit (this->unit_);
  return 0;
}
