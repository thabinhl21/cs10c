#include "Vertex.h"
#include "Graph.h"

Graph::Graph() {

}


// Reads the graph input file and instantiates a graph object.
Graph::Graph(ifstream &inFS) {
    int numNodes;
    int numEdges;
    string nodeLabel;
    string sourceVertex;
    string sinkVertex;
    int weight;

    inFS >> numNodes >> numEdges;

    // read in all of the nodes, create a new Vertex object and add it to Graph vector
    for (int i = 0; i < numNodes; ++i) {
        inFS >> nodeLabel;
        Vertex node;
        node.label = nodeLabel;
        vertices.push_back(node);
    }

    int index;
    int neighborIndex;
    pair<int,int> pairs;

    for (int i = 0; i < numEdges; ++i) {
        inFS >> sourceVertex >> sinkVertex >> weight;


        for (unsigned int j = 0; j < vertices.size(); ++j) {

            if (vertices.at(j).label == sourceVertex) {
                index = j;
            }
            if (vertices.at(j).label == sinkVertex) {
                neighborIndex = j;
            }

        }
        pairs = make_pair(neighborIndex, weight);
        vertices.at(index).neighbors.push_back(pairs);

    }

}

Graph::~Graph() {
    while (!vertices.empty()) {
        vertices.pop_back();
    }
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