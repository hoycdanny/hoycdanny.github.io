// $Id: StatisticsHelper.cpp 1861 2011-08-31 16:18:08Z mesnierp $
#include "StatisticsHelper.h"

// swap function for integers
void swap ( CORBA::Long& x, CORBA::Long& y )
{
  CORBA::Long temp;
  temp = x;
  x = y;
  y = temp;
}


void sort ( LongVector & vector )
{
  unsigned size = vector.size ();

  if (size > 0)
    {
      unsigned indexOfMin;
      unsigned pass;
      unsigned j;

      for ( pass = 0; pass < size - 1; pass++ )
      {
        indexOfMin = pass;

        for ( j = pass + 1; j < size; j++ )
          if ( vector[j] < vector[indexOfMin] )
            indexOfMin = j;

        swap ( vector[pass], vector[indexOfMin] );
      }
    }
}
