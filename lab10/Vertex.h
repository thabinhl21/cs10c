#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>
#include <map>
#include <climits>

using namespace std;

class Vertex {
public:
  list<pair<int, int> > neighbors;
  string label;
  int distance;
  string color;
  Vertex* prev;
  
  /*
  A vector containing all of the vertices in the graph. 
  The start vertex is in the first position in the vector.
  */
  Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};

#endif /* VERTEX_H_ */
