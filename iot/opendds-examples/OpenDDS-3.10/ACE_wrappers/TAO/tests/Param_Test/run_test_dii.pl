eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id: run_test_dii.pl 14 2007-02-01 15:49:12Z mitza $
# -*- perl -*-

system 'perl run_test.pl -i dii ' . join ' ', @ARGV;

