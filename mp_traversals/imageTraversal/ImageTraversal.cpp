#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_=NULL;
  finish=1;
}

ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, Point start, PNG png,double tolerance){
  traversal_=traversal;
  start_=start;
   png_=png;
   tolerance_=tolerance;
   finish=0;
   current=traversal_->peek();
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  //ADD
  unsigned width=png_.width();
  unsigned height=png_.height();
  traversal_->pop();
  traversal_->setVisited(current.x,current.y);
  // cs225::HSLAPixel currentPixel=png_.getPixel(current.x,current.y);
  cs225::HSLAPixel startPixel=png_.getPixel(start_.x,start_.y);
  if(current.x+1<width){
    cs225::HSLAPixel right=png_.getPixel(current.x+1,current.y);
    double rightTolerance=calculateDelta(startPixel,right);
    if(rightTolerance<tolerance_){
      if(!traversal_->getVisited(current.x+1,current.y)){
        // std::cout <<"x "<< current.x+1 << ' ';
        // std::cout << "y "<<current.y << '\n';
        traversal_->add(Point(current.x+1,current.y));
      }
    }
  }
  if(current.y+1<height){
    cs225::HSLAPixel below=png_.getPixel(current.x,current.y+1);
    double belowTolerance=calculateDelta(startPixel,below);
    if(belowTolerance<tolerance_){
      if(!traversal_->getVisited(current.x,current.y+1)){
        // std::cout <<"x "<< current.x << ' ';
        // std::cout << "y "<<current.y+1 << '\n';
        traversal_->add(Point(current.x,current.y+1));
      }
    }
  }
  if(current.x>=1){
    cs225::HSLAPixel left=png_.getPixel(current.x-1,current.y);
    double leftTolerance=calculateDelta(startPixel,left);
    if(leftTolerance<tolerance_){
      // std::cout <<"x-1 "<< current.x-1 ;
      // std::cout << " y"<<current.y << '\n';
      if(!traversal_->getVisited(current.x-1,current.y)){
        traversal_->add(Point(current.x-1,current.y));
      }
    }
  }
  if(current.y>=1){
    cs225::HSLAPixel above=png_.getPixel(current.x,current.y-1);
    double aboveTolerance=calculateDelta(startPixel,above);
    if(aboveTolerance<tolerance_){
      if(!traversal_->getVisited(current.x,current.y-1)){
        // std::cout <<"x "<< current.x;
        // std::cout << " y "<<current.y-1 << '\n';
        traversal_->add(Point(current.x,current.y-1));
      }
    }
  }
  while((!traversal_->empty())&&(traversal_->getVisited(traversal_->peek().x,traversal_->peek().y)))
    {
  current=traversal_->pop();
    }
  if(traversal_->empty()){
    finish=1;
    return *this;
    }
  else{
  current=traversal_->peek();
  return *this;}
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
  // return Point(0, 0);
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
    // return (!traversal_->empty()&&other.traversal_->empty());
    return !(finish&&other.finish);
}
