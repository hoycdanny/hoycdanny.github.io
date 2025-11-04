$Id: README.txt 2367 2014-10-06 20:40:46Z mesnierp $

Tests reconnection when a group of servers share a portspan, and restart in a different
order. Automated test uses C++ client only. To test Java, first build C++, then use
ant to build Java client, dependent on JacORB 3.6. Set your $JACORB_HOME then run
./runtest.pl -java
