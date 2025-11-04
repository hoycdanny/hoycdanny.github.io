package GNUIDLObjectGenerator;

# ************************************************************
# Description   : Generates object files for GNU IDL Makefiles.
# Author        : Chip Jones
# Create Date   : 11/01/2011
# $Id: GNUIDLObjectGenerator.pm 2793 2015-11-30 23:09:18Z mitza $
# ************************************************************

# ************************************************************
# Pragmas
# ************************************************************

use strict;
use ObjectGenerator;

use vars qw(@ISA);
@ISA = qw(ObjectGenerator);

# ************************************************************
# Subroutine Section
# ************************************************************

sub process {
  my($noext) = $_[1];
  $noext =~ s/\.[^\.]+$//o;
  $noext =~ s/.+\/// if $noext =~ /\.\.\//;
  return ["\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_CLIENT_HDR_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_CLIENT_INL_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_CLIENT_SRC_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_SERVER_HDR_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_SERVER_SRC_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_SERVER_THDR_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_SERVER_TINL_EXT)",
          "\$(IDL_GEN_FILES_DIR)\/$noext\$(IDL_SERVER_TSRC_EXT)"
         ];
}

1;
