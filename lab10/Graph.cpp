#include "Vertex.h"
#include "Graph.h"

Graph::Graph() {
    return;
}


// Reads the graph input file and instantiates a graph object.
Graph::Graph(ifstream &inFS) {
    return;
}

Graph::~Graph() {
    return;
}

/*
Outputs graph object to a .dot file, then makes a system call that calls dotty on this file. 
In the dotty file, each node should include vertex label and its distance value.
*/
void Graph::output_graph(const string &) {
    return;
}

/*
Breadth First Search. Via a BFS traversal, this function should assign each 
individual vertex's distance to the number of hops that the vertex is from the start vertex.
*/
void Graph::bfs() {
    return;
}