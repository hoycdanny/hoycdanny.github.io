#!/pkg/gnu/bin//perl5
#
#$Id: killbench.pl 14 2007-02-01 15:49:12Z mitza $
#

push(@INC, "$wd/bin");
require('WebStone-common.pl');

html_begin();

print CLIENT "<P>Killing WebStone processes<PRE>";
system("$wd/bin/killbench");
print CLIENT "</PRE><P>Done.";

html_end();

# end
