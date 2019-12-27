#include "StickerSheet.h"

StickerSheet::StickerSheet(const Image &picture, unsigned max){
  currnumber=0;
  max_=max;
  base=new Image(picture);
  x_=new unsigned[max_];
  y_=new unsigned[max_];
  stickers = new Image* [max_];
}

StickerSheet::~StickerSheet(){
  delete [] stickers;
  delete []x_;
  delete []y_;
  delete base;
}

StickerSheet::StickerSheet(const StickerSheet &other){
  base=new Image (*other.base);
  currnumber=other.currnumber;
  max_= other.max_;
  stickers = new Image* [max_];
  x_=new unsigned[max_];
  y_=new unsigned[max_];
  for(unsigned i=0;i<currnumber;i++){
    stickers[i]= other.stickers[i];
    x_[i]=other.x_[i];
    y_[i]=other.y_[i];
  }
}

const StickerSheet & StickerSheet::operator=(const StickerSheet &other){
  //if(this!=other) necessary?
  delete [] stickers;
  delete []x_;
  delete []y_;
  delete base;
  base=new Image (*other.base);
  max_= other.max_;
  currnumber=other.currnumber;
  stickers = new Image* [max_];
  x_=new unsigned[max_];
  y_=new unsigned[max_];
  for(unsigned i=0;i<currnumber;i++){
    stickers[i]= other.stickers[i];
    x_[i]=other.x_[i];
    y_[i]=other.y_[i];
  }
  return *this; //as the templet
}

void StickerSheet::changeMaxStickers(unsigned max){
  if(max<currnumber){
    unsigned *x_new=new unsigned[max];
    unsigned *y_new=new unsigned[max];
    Image **stickers_new = new Image* [max];
    for(unsigned i=0;i<max;i++){
        stickers_new[i]=stickers[i];
        x_new[i]=x_[i];
        y_new[i]=y_[i];
    }
    delete []x_;
    delete []y_;
    delete []stickers;
  stickers=stickers_new;
  x_=x_new;
  y_=y_new;
  max_=max;
  currnumber=max;
  }
  else if (max>max_) {
    unsigned *x_new=new unsigned[max];
    unsigned *y_new=new unsigned[max];
    Image **stickers_new = new Image* [max];
    for(unsigned i=0;i<currnumber;i++){
        stickers_new[i]=stickers[i];
        x_new[i]=x_[i];
        y_new[i]=y_[i];
    }
    delete []x_;
    delete []y_;
    delete []stickers;
    stickers=stickers_new;
    x_=x_new;
    y_=y_new;
    max_=max;
  }
  else{
    max_=max;}
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
  if((currnumber+1)<=max_){
    currnumber=currnumber+1;
    stickers[currnumber-1]=&sticker;//not sure
    x_[currnumber-1]=x;
    y_[currnumber-1]=y;
    return (currnumber-1);
  }
  else{return (-1);}
}

Image* StickerSheet::getSticker(unsigned index){
  if((index+1)<=currnumber){
    return stickers[index];
  }
  else{
    return NULL;
  }
}

void StickerSheet::removeSticker(unsigned index){
  for(unsigned i=index;i<(currnumber-1);i++){
    stickers[i]=stickers[i+1];
    x_[i]=x_[i+1];
    y_[i]=y_[i+1];
  }
  unsigned *x_new=new unsigned[max_];
  unsigned *y_new=new unsigned[max_];
  Image **stickers_new = new Image* [max_];
  currnumber=currnumber-1;
  for(unsigned i=0;i<(currnumber);i++){
      stickers_new[i]=stickers[i];
      x_new[i]=x_[i];
      y_new[i]=y_[i];
  }
  delete []x_;
  delete []y_;
  delete []stickers;
  stickers=stickers_new;
  x_=x_new;
  y_=y_new;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
  if((index+1)<=currnumber){
    x_[index]=x;
    y_[index]=y;
    return true;
  }
  else{
    return false;
  }
}

Image StickerSheet::render() const{
  Image *newBase=new Image (*base);
  unsigned newWidth= newBase->width();
  unsigned newHeight= newBase->height();
  for(unsigned i=0;i<currnumber;i++){
    if((x_[i]+stickers[i]->width())>newWidth){
      newWidth=x_[i]+stickers[i]->width();}
      if((y_[i]+stickers[i]->height())>newHeight){
        newHeight=y_[i]+stickers[i]->height();}
    }
    newBase->resize(newWidth,newHeight);
    for(unsigned i=0;i<currnumber;i++){
      for (unsigned x = x_[i]; x <(x_[i]+stickers[i]->width()); x++) {
        for (unsigned y = y_[i]; y <(y_[i]+stickers[i]->height()); y++) {
          cs225::HSLAPixel & pixel_base =newBase->getPixel(x, y);
          cs225::HSLAPixel & pixel_sticker = stickers[i]->getPixel((x-x_[i]), (y-y_[i]));
          if(pixel_sticker.a!=0){
            pixel_base=pixel_sticker;
          }
        }
      }
    }
    Image newPicture=(*newBase);
    delete newBase;//not sure
    return newPicture;
}
