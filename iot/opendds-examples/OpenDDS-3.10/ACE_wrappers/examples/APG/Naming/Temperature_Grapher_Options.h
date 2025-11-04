// $Id: Temperature_Grapher_Options.h 14 2007-02-01 15:49:12Z mitza $

#ifndef TEMPERATURE_GRAPHER_OPTIONS_H
#define TEMPERATURE_GRAPHER_OPTIONS_H

class Temperature_Grapher_Options
  {
  public:
    Temperature_Grapher_Options( int argc, ACE_TCHAR ** argv )
    {
      ACE_UNUSED_ARG(argc);
      ACE_UNUSED_ARG(argv);
    }

    int poll_interval()
    {
      return 20; // every 20 seconds
    }
  };

#endif /* TEMPERATURE_GRAPHER_OPTIONS_H */
