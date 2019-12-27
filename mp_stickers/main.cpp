#include "Image.h"
#include "StickerSheet.h"

int main() {
  Image background; background.readFromFile("battle.png");
  Image myHead;    myHead.readFromFile("myHead.png");
  Image rapgod; rapgod.readFromFile("rapgod.png");
  Image chain;    chain.readFromFile("chain.png");


  StickerSheet sheet(background, 5);
  sheet.addSticker(chain,500, 150);
  sheet.addSticker(myHead,453, 7);
  sheet.addSticker(rapgod,0,0 );

  Image newPicture=sheet.render();

  newPicture.writeToFile("myImage.png");
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}
