#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <queue>

/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;
  std::unordered_map<std::string,std::string> prev;
  std::queue<std::string> q;
  std::unordered_map<string, bool> vertexVisited;
  bool found=false;

  for(auto v:vertexMap){
    vertexVisited.insert({v.first, false});
  }
  q.push(start);
  prev.insert({start, start});
  vertexVisited.at(start)=true;
  while(!found){
    string curr=q.front();
    q.pop();
    std::list<std::reference_wrapper<E>> edges=incidentEdges(curr);
    for(Edge e:edges){
      if(e.source().key()==end){
        found=true;
      }
      if(e.dest().key()==end){
        found=true;
      }
      if(!vertexVisited.at(e.source().key())){
        q.push(e.source().key());
        prev.insert({e.source().key(),curr});
        vertexVisited.at(e.source().key())=true;
      }
      if(!vertexVisited.at(e.dest().key())){
        q.push(e.dest().key());
        prev.insert({e.dest().key(),curr});
        vertexVisited.at(e.dest().key())=true;
      }
    }
  }
  path.push_front(end);
  std::string temp=end;
  while(temp!=start){
    std::string p=prev.at(temp);
    path.push_front(p);
    temp=p;
  }

  return path;
}
