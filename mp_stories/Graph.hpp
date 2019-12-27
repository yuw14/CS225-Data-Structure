#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>

/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::numVertices() const {
  // TODO: Part 2
  return vertexMap.size();
  // return 0;
}


/**
* The degree of the vertex. For directed: Sum of in-degree and out-degree
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
  return adjList.at(v.key()).size();
  // return 0;
}


/**
* Inserts a Vertex into the Graph.
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));
  // vertexMap.emplace(key,v);
  vertexMap.insert({key,v});
  // std::list<edgeListIter> empty;
  adjList.insert({key,std::list<edgeListIter>()});
  return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges=incidentEdges(key);
  for(Edge e:edges){
    removeEdge(e.source().key(),e.dest().key());
  }
  // for(edgeListIter it:adjList.at(key)){
  //   string s=it->get().source().key();
  //   string d=it->get().dest().key();
  //   removeEdge(s,d);
  // }
  adjList.erase(key);
  vertexMap.erase(key);

}


/**
* Inserts an Edge into the Graph.
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
  E & e = *(new E(v1, v2));
  edgeList.push_front(e);
  adjList.at(v1.key()).push_front(edgeList.begin());
  adjList.at(v2.key()).push_front(edgeList.begin());
  return e;
}


/**
* Removes an Edge from the Graph. Consider both the undirected and directed cases.
* min(degree(key1), degree(key2))
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {
  // TODO: Part 2
  for(edgeListIter it=edgeList.begin();it!=edgeList.end();it++){
    Edge e=(*it);
    if(e.source().key()==key1 && e.dest().key()==key2){
      removeEdge(it);
      break;
    }
    if(e.source().key()==key2&&e.dest().key()==key1&&e.directed()){
      removeEdge(it);
      break;
    }
  }
}


/**
* Removes an Edge from the Graph given by the location of the given iterator into the edge list.
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
  Edge e=(*it);
  V s=e.source();
  V d=e.dest();
  adjList.at(s.key()).remove(it);
  adjList.at(d.key()).remove(it);
  edgeList.erase(it);

}


/**
* Return the list of incident edges from a given vertex.
* For the directed case, consider all edges that has the vertex as either a source or destination.
* @param key The key of the given vertex
* @return The list edges (by reference) that are adjacent to the given vertex
*/
template <class V, class E>
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;
  for(edgeListIter it:adjList.at(key)){
    edges.push_back(*it);
  }
  return edges;
}


/**
* Return whether the two vertices are adjacent to one another. Consider both the undirected and directed cases.
* When the graph is directed, v1 and v2 are only adjacent if there is an edge from v1 to v2.
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
  std::list<edgeListIter> adj1 = adjList.at(key1);
  std::list<edgeListIter> adj2 = adjList.at(key2);
  if(adj1.empty()||adj2.empty()){return false;}
  if(adj1.front()->get().directed()){
    for(edgeListIter e1:adj1){
      if(e1->get().dest().key()==key2){return true;}
    }
  }
  else{
    unsigned int degree1=degree(key1);
    unsigned int degree2=degree(key2);
    if(degree1<degree2){
      for(edgeListIter e1:adj1){
        for(edgeListIter e2:adj2){
          if(e1==e2){return true;}
        }
      }
    }
    else{
        for(edgeListIter e2:adj2){
          for(edgeListIter e1:adj1){
            if(e1==e2){return true;}
          }
        }
    }
  }
  return false;




  // std::list<std::reference_wrapper<E>> iEkey1=incidentEdges(key1);
  // for(Edge e:iEkey1){
  //   std::cout << "e.source: " << e.source().key() << " e.dest: " << e.dest().key() << '\n';
  //   if (e.directed()) {
  //     std::cout << "sksksk\n" << '\n';
  //   }
  //
  //   if(e.source().key()==key1&&e.dest().key()==key2){
  //     std::cout << "condition1" << '\n';
  //     return true;
  //   }
  //   if(e.source().key()==key2&&e.dest().key()==key1&&!e.directed()){
  //     std::cout << "condition2" << '\n';
  //     return true;
  //   }
  // }
  // return false;
}
