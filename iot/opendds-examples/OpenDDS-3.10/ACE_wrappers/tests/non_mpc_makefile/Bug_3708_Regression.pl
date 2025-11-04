eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id: Bug_3708_Regression.pl 2645 2015-08-26 16:17:13Z mitza $
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";

# This test can't run on Win32
exit if ($^O eq 'MSWin32');

# This test can't be run if "make" is not in the path or if it resolves to
# a non-GNU version of make.

exit unless (`make --version` =~ /^GNU Make/);

print "Running non_mpc_makefile test:\n";
system "make -f CustomMakefile";
print "ERROR: libfoo.a not made\n" unless -r 'libfoo.a';
system "make -f CustomMakefile realclean";
