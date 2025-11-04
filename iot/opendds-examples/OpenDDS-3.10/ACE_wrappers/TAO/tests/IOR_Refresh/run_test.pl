eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id: run_test.pl 2646 2015-08-28 00:38:05Z mesnierp $
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;
$debug_level = '0';
$server_name = "server";
$decimal = "-ORBDottedDecimalAddresses 1 ";
$nodecimal = "-ORBDottedDecimalAddresses 0 ";
$shared = "-ORBUseSharedProfiles 1 ";
$noshared = "-ORBUseSharedProfiles 0 ";
$svcconf = "-ORBSvcConf refresh.conf ";

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    }
}

$server = PerlACE::TestTarget::create_target (1) || die "Create failed\n";
$client = PerlACE::TestTarget::create_target (2) || die "Create failed\n";

$port = $client->RandomPort ();

$base_arg = "-ORBdebuglevel $debug_level -ORBListenEndpoints iiop://:$port ";
@test_arg;
$test_arg[0] = $base_arg . $decimal . $shared;
$test_arg[1] = $base_arg . $decimal . $noshared;
$test_arg[2] = $base_arg . $nodecimal;
$test_arg[3] = $base_arg . $decimal . $shared . $svcconf;

$CL = $client->CreateProcess ("client", "-ORBdebuglevel $debug_level -p $port");

for ($i = 0; $i < 4; $i++) {
    $SV = $server->CreateProcess ($server_name, $test_arg[$i]);

    print "Starting $server_name $test_arg[$i]\n";
    $server_status = $SV->Spawn ();

    if ($server_status != 0) {
        print STDERR "ERROR: server returned $server_status\n";
        exit 1;
    }

    sleep(3);

    print "Client\n";
    $client_status = $CL->SpawnWaitKill ($client->ProcessStopWaitInterval());;

    if ($client_status != 0) {
        print STDERR "ERROR: client returned $client_status\n";
        $SV->Kill (); $SV->TimedWait (1);
        exit 1;
    }

    $server_status = $SV->WaitKill ($server->ProcessStopWaitInterval());

    if ($server_status != 0) {
        print STDERR "ERROR: server returned $server_status\n";
        $status = 1;
    }
}

exit $status;
