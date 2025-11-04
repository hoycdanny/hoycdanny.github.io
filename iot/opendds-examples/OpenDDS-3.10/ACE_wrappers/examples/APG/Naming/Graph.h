// $Id: Graph.h 14 2007-02-01 15:49:12Z mitza $

#ifndef GRAPH_H
#define GRAPH_H

#include "Graphable_Element.h"

class Graph
  {
  public:
    Graph()
    {
    }

    void graph( char * filename, Graphable_Element_List & data );
  };

#endif /* GRAPH_H */
