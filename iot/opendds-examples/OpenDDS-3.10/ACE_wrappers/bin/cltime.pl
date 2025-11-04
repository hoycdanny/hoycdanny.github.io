# $Id: cltime.pl 14 2007-02-01 15:49:12Z mitza $
use strict;

my($name)  = shift;
my($email)  = shift;
my($entry) = scalar(gmtime());

my($tz) = 'UTC';
$entry =~ s/(:\d\d\s+)(.*)(\d\d\d\d)$/$1$tz $3/;

$entry .= "  $name <$email>";

print $entry;
