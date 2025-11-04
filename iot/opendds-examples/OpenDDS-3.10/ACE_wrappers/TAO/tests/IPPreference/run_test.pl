eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id: run_test.pl 2465 2015-02-18 17:08:32Z mesnierp $
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;
$debug_level = '0';
foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    }
    if ($i eq '-cdebug') {
      $cdebug_level = '10';
    }
}

my $testexe = PerlACE::TestTarget::create_target (1) || die "Create target 2 failed\n";

$CL = $testexe->CreateProcess ("test", "-ORBdebuglevel $debug_level");

$res = $CL->SpawnWaitKill ($testexe->ProcessStartWaitInterval());

if ($res != 0) {
    print STDERR "ERROR: default test FAIL\n";
    $status = 1;
}

$CL->Arguments ("-ORBdebuglevel $debug_level -ORBPreferIPv6Interfaces 0");

$res = $CL->SpawnWaitKill ($testexe->ProcessStartWaitInterval());

if ($res != 0) {
    print STDERR "ERROR: want IPv4 test FAIL\n";
    $status += 2;
}

$CL->Arguments ("-ORBdebuglevel $debug_level -ORBPreferIPv6Interfaces 1");

$res = $CL->SpawnWaitKill ($testexe->ProcessStartWaitInterval());

if ($res != 0) {
    print STDERR "ERROR: want IPv6 test FAIL\n";
    $status += 2;
}

exit $status;
