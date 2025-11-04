package VXTestWorkspaceCreator;

# ************************************************************
# Description   : VxTest Workspace create
# Author        : Johnny Willemsen
# Create Date   : 28/03/2008
# $Id: VXTestWorkspaceCreator.pm 2179 2013-05-28 22:16:51Z mesnierp $
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;

use VXTestProjectCreator;
use WorkspaceCreator;

use vars qw(@ISA);
@ISA = qw(WorkspaceCreator);

# ************************************************************
# Subroutine Section
# ************************************************************

sub write_workspace {
  return 1;
}

1;
