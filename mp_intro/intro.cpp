#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>



void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG original;
  original.readFromFile(inputFile);
  unsigned width=original.width();
  unsigned height=original.height();
  cs225::PNG output=original;
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      cs225::HSLAPixel& pixel1 = original.getPixel(x,y);
      cs225::HSLAPixel& pixel2 =output.getPixel(width-x-1,height-y-1);
      pixel2=pixel1;
    }
  }
  output.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for (unsigned x=0 ;x<width;x++){
    for(unsigned y=0;y<height;y++){
      cs225::HSLAPixel&pixel=png.getPixel(x,y);
      pixel.l=0.5;
      pixel.s=0.5;
      pixel.h=((x*1.0)/width)*360;
    }
  }

  return png;
}
