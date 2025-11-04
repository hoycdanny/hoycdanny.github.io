/**
 * @file Clock_Ticks.cpp
 *
 * $Id: Clock_Ticks.cpp 1861 2011-08-31 16:18:08Z mesnierp $
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 *
 */
#include "Clock_Ticks.h"

long
Clock_Ticks::get_hz (void)
{
#if defined(_SC_CLK_TCK)
  long r = ACE_OS::sysconf(_SC_CLK_TCK);
  if(r != -1)
    return r;
#endif /* _SC_CLK_TCK */

#if defined(CLK_TCK)
  return CLK_TCK;
#elif defined(HZ)
  return HZ;
#else
  return 100; // A good guess for most systems!
#endif /* CLK_TCK */
}

int
Clock_Ticks::get_usecs_per_tick (void)
{
  return 1000000 / get_hz ();
}
