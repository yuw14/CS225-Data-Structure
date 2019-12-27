/**
 * @file NetworkFlow.cpp
 * CS 225: Data Structures
 */

#include <vector>
#include <algorithm>
#include <set>

#include "graph.h"
#include "edge.h"

#include "NetworkFlow.h"

int min(int a, int b) {
  if (a<b)
    return a;
  else return b;
}

NetworkFlow::NetworkFlow(Graph & startingGraph, Vertex source, Vertex sink) :
  g_(startingGraph), residual_(Graph(true,true)), flow_(Graph(true,true)), source_(source), sink_(sink) {

  // YOUR CODE HERE
  maxFlow_=0;
  vector<Vertex> vertices=g_.getVertices();
  for(Vertex v:vertices){
    residual_.insertVertex(v);
    flow_.insertVertex(v);
  }
  vector<Edge> edges=g_.getEdges();
  for(Edge e:edges){
    Vertex s=e.source;
    Vertex d=e.dest;
    flow_.insertEdge(s,d);
    flow_.setEdgeWeight(s,d,0);
    flow_.setEdgeLabel(s,d,s+d);
    int edgeWeight=g_.getEdgeWeight(s,d);
    residual_.insertEdge(s,d);
    residual_.insertEdge(d,s);
    residual_.setEdgeWeight(s,d,edgeWeight);
    residual_.setEdgeWeight(d,s,0);
    residual_.setEdgeLabel(s,d,s+d);
    residual_.setEdgeLabel(d,s,d+s);
  }
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the helper function.
   *
   * @param source  The starting (current) vertex
   * @param sink    The destination vertex
   * @param path    The vertices in the path
   * @param visited A set of vertices we have visited
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink,
  std::vector<Vertex> &path, std::set<Vertex> &visited) {

  if (visited.count(source) != 0)
    return false;
  visited.insert(source);

  if (source == sink) {
    return true;
  }

  vector<Vertex> adjs = residual_.getAdjacent(source);
  for(auto it = adjs.begin(); it != adjs.end(); it++) {
    if (visited.count(*it) == 0 && residual_.getEdgeWeight(source,*it) > 0) {
      path.push_back(*it);
      if (findAugmentingPath(*it,sink,path,visited))
        return true;
      else {
        path.pop_back();
      }
    }
  }

  return false;
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the main function.  It initializes a set to keep track of visited vertices.
   *
   * @param source The starting (current) vertex
   * @param sink   The destination vertex
   * @param path   The vertices in the path
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, std::vector<Vertex> &path) {
   std::set<Vertex> visited;
   path.clear();
   path.push_back(source);
   return findAugmentingPath(source,sink,path,visited);
}

  /**
   * pathCapacity - Determine the capacity of a path in the residual graph.
   *
   * @param path   The vertices in the path
   */

int NetworkFlow::pathCapacity(const std::vector<Vertex> & path) const {
  // YOUR CODE HERE
  int capacity=INT_MAX;
  for(unsigned i=0;i<(path.size()-1);i++){
    Vertex v1=path[i];
    Vertex v2=path[i+1];
    int tempWeight=residual_.getEdgeWeight(v1,v2);
    if(tempWeight<capacity){
      capacity=tempWeight;
    }
  }
  return capacity;
  // return 0;
}

  /**
   * calculuateFlow - Determine the capacity of a path in the residual graph.
   * Sets the member function `maxFlow_` to be the flow, and updates the
   * residual graph and flow graph according to the algorithm.
   *
   * @return The network flow graph.
   */

const Graph & NetworkFlow::calculateFlow() {
  // YOUR CODE HERE
  vector<Vertex> path;
  while(findAugmentingPath(source_,sink_,path)){
    int capacity=pathCapacity(path);
    maxFlow_+=capacity;
    for(unsigned i=0;i<path.size()-1;i++){
      Vertex s=path[i];
      Vertex d=path[i+1];
      int weightFlow;
      if(flow_.edgeExists(s,d)){
        weightFlow=flow_.getEdgeWeight(s,d);
        flow_.setEdgeWeight(s,d,weightFlow+capacity);
      }
      else{
        weightFlow=flow_.getEdgeWeight(d,s);
        flow_.setEdgeWeight(d,s,weightFlow-capacity);
      }
      int weightResidual=residual_.getEdgeWeight(s,d);
      int weightResidualReverse=residual_.getEdgeWeight(d,s);
      residual_.setEdgeWeight(s,d,weightResidual-capacity);
      residual_.setEdgeWeight(d,s,weightResidualReverse+capacity);
    }
  }
  return flow_;
}

int NetworkFlow::getMaxFlow() const {
  return maxFlow_;
}

const Graph & NetworkFlow::getGraph() const {
  return g_;
}

const Graph & NetworkFlow::getFlowGraph() const {
  return flow_;
}

const Graph & NetworkFlow::getResidualGraph() const {
  return residual_;
}
