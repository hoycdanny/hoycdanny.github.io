package GNUAutobuildProjectCreator;

# ************************************************************
# Description   : A Project creator for the GNUAutobuild project type
# Author        : Chad Elliott
# Create Date   : 3/13/2002
# $Id: GNUAutobuildProjectCreator.pm 2179 2013-05-28 22:16:51Z mesnierp $
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;
use File::Basename;

use GNUACEProjectCreator;
use MakeProjectBase;
use ProjectCreator;

use vars qw(@ISA);
@ISA = qw(GNUACEProjectCreator MakeProjectBase ProjectCreator);

sub extractType {
    return 'gnuace';
}

1;
