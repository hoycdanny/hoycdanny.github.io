/*
 * $Id: ping.x 943 2008-12-12 15:11:28Z mitza $
 */

/*
 * A small program to test RPC round-trip delays.
 */
program PINGPROG {
  version PINGVERS {
    int PING (int) = 1;
  } = 1;
} = 0x20000001;
