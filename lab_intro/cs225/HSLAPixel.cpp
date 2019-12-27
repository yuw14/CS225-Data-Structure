/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
  HSLAPixel::HSLAPixel(){
  a=1.0;
  l=1;
  s=0.0;
  h=0;}
  HSLAPixel::HSLAPixel(double hue,double saturation,double luminance){
    a=1.0;
    l=luminance;
    h=hue;
    s=saturation;

  }
  HSLAPixel::HSLAPixel(double hue,double saturation,double luminance,double alpha){
    h=hue;
    l=luminance;
    s=saturation;
    a=alpha;
  }



}
