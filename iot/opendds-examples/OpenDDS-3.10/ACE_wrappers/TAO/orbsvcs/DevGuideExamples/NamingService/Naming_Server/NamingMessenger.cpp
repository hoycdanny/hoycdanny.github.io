// $Id: NamingMessenger.cpp 2858 2016-06-09 15:40:28Z mesnierp $

#include "NamingTask.h"
#include "MessengerTask.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  // Start the Naming Service task
  NamingTask namingService(argc, argv);
  namingService.activate();
  // Wait for the Naming Service initialized.
  namingService.waitInit();

  // Start the Messenger task
  MessengerTask messenger;
  messenger.activate();

  // Wait the Messenger task finish.
  messenger.wait();
  // Shutdown the Naming Service.
  namingService.end();

  return 0;
}
