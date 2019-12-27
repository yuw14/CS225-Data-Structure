
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

PNG getTestPNG() {
  PNG png(4, 4);
  HSLAPixel blackPixel(180, 1, 0);

  for (unsigned i = 0; i < 4; i++) {
    png.getPixel(i, 0) = blackPixel;
    png.getPixel(0, i) = blackPixel;
    png.getPixel(i, 3) = blackPixel;
    png.getPixel(3, i) = blackPixel;
  }

  return png;
}

int main() {

  //tolerance?
  //current PNG?

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  PNG png1;
  PNG myHead;
  png1.readFromFile("traversal_base.png");
  myHead.readFromFile("myHead.png");

  FloodFilledImage image(png1);
  BFS bfs1(png1,Point(1,1),0.2);
  DFS dfs1(png1,Point(49,49),0.5);

  RainbowColorPicker rainbow(0.1);
  MyColorPicker my=MyColorPicker(myHead);

  image.addFloodFill(bfs1,rainbow);
  image.addFloodFill(dfs1,my);
  Animation animation=image.animate(1000);

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");

  PNG png = getTestPNG();
  Point startPoint(1, 1);

  BFS bfs(png, startPoint, 0.2);
  ImageTraversal::Iterator it = bfs.begin();
  ++it;


  return 0;
}
