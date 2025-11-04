#!/pkg/gnu/bin//perl5
#
#$Id: move-runs.pl 14 2007-02-01 15:49:12Z mitza $
#

push(@INC, "$wd/bin");
require('WebStone-common.pl');

html_begin();

if ($runsdir ne $oldrunsdir) {
    print CLIENT "<BODY>Moving $oldrunsdir to $runsdir...";
    if (-e $runsdir) {
	print CLIENT "<STRONG>Error: $runsdir already exists!</STRONG>";
    }
    rename($oldrunsdir, $runsdir);
    print CLIENT "<P>Done.";
}
else
{
    print CLIENT "<STRONG>Can't move $runsdir <P>to $oldrunsdir</STRONG>";
}

html_end();

# end
