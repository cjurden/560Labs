#ifndef TREE_H
#define TREE_H
#include "Graph.h"
#include "Skew.h"
#include "Set.h"
#include <fstream>
#include <iostream>

using namespace std;

class Tree
{
  private:

  public:
    Tree();
    int numG;
      //Graph** graphs;

    Graph* Kruskal(Graph* g);
    Graph* Prims(Graph* g);
    void printGraph(Graph* g);

    //Graph* buildGraph(int size, ifstream infile);
    int countEdge(Graph* g);
    int calcCost(Graph* g);
};
#include "Tree.hpp"
#endif
