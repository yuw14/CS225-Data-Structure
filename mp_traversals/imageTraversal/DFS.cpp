#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 *
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  png_=png;
  start_=start;
  tolerance_=tolerance;
  s.push(start_);
  unsigned width=png_.width();
  unsigned height=png_.height();
  visited.resize(width);
  for(unsigned x=0;x<width;x++){
    visited[x].resize(height);
    for(unsigned y=0;y<height;y++){
      visited[x][y]=0;
    }
  }
  visited[start_.x][start_.y]=1;
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this,start_,png_,tolerance_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
    s.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point top=s.top();
  s.pop();
  return top;
  // return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  // if(s.empty()){return NULL;}
  return s.top();
  // return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if(s.empty()){
  return true;}
  else{return false;}
}

bool DFS::getVisited(unsigned x, unsigned y){
  return visited[x][y];
}
void DFS::setVisited(unsigned x, unsigned y){
  visited[x][y]=1;
}
