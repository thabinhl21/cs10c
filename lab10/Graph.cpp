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

    // for testing purposes
    for (unsigned int i = 0; i < vertices.size(); ++i) {
        cout << vertices.at(i).label << endl;
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
void Graph::output_graph(const string &fN) {
    return;
}

/*
Breadth First Search. Via a BFS traversal, this function should assign each 
individual vertex's distance to the number of hops that the vertex is from the start vertex.
*/

// algorithm from https://d1b10bmlvqabco.cloudfront.net/attach/ilv1r6m8xjc64o/h7ks2ibk8jg6s3/ioki9sunvh1o/graphs.pdf
void Graph::bfs() {

    for (unsigned int u = 0; u < vertices.size(); ++u) {
        vertices.at(u).color = "WHITE"; //white is undiscovered
        vertices.at(u).distance = INT_MAX; //distance from source vertex
        vertices.at(u).prev = 0; //previous vertex
    }

    vertices.at(0).color = "GRAY"; 
    vertices.at(0).distance = 0;
    vertices.at(0).prev = 0;

    queue<Vertex*> vQueue;
    vQueue.push(&vertices.at(0));

    while (!vQueue.empty()) {
        Vertex* curr = vQueue.front();
        vQueue.pop();

        
        for (list<pair<int, int> >::iterator v = curr->neighbors.begin(); v != curr->neighbors.end();) {
            cout << "testing 1" << endl;
            if (vertices.at(v->first).color == "WHITE") {
                vertices.at(v->first).color = "GRAY";   // gray is discovered, but not expanded
                vertices.at(v->first).distance = curr->distance + v->second;
                vertices.at(v->first).prev = curr;
                vQueue.push(&vertices.at(v->first));
            }
            ++v;
        }
        curr->color = "BLACK";  // black is expanded
        vQueue.pop();
    }
}