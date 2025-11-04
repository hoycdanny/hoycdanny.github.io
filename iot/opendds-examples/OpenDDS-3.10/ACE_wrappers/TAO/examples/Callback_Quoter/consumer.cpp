// $Id: consumer.cpp 935 2008-12-10 21:47:27Z mitza $

#include "Consumer_Handler.h"

// This function runs the Callback Quoter Consumer application.

int
ACE_TMAIN(int argc, ACE_TCHAR *argv[])
{
  Consumer_Handler consumer;

  ACE_DEBUG ((LM_DEBUG,
              "\n\t***Consumer***\n\n"));

  if (consumer.init (argc, argv) == -1)
    return -1;
  else
    return consumer.run ();
}
