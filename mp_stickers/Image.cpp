#include "Image.h"
#include "cs225/HSLAPixel.h"
#include "math.h"
using  cs225::HSLAPixel;


/*
Image a, b, c;
a.lighten();

b.l
*/
void Image::lighten(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.l= pixel.l+0.1;
      if(pixel.l>1){
        pixel.l=1;}
    }
  }
};

void Image::lighten(double amount) {
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.l= pixel.l+amount;
      if(pixel.l>1){
        pixel.l=1;
      }
    }
}
};

void Image::darken(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.l= pixel.l-0.1;
      if(pixel.l<0){
        pixel.l=0;
      }
  }
    }
};

void Image::darken(double amount){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.l= pixel.l-amount;
      if(pixel.l<0){
        pixel.l=0;}
    }
}
};

void Image::saturate(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s= pixel.s+0.1;
    }
}
};

void Image::saturate(double amount){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s= pixel.s+amount;
    }
}
};

void Image::desaturate(){

  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s= pixel.s-0.1;
    }
}
};

void Image::desaturate(double amount){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s= pixel.s-amount;
    }
}
};

void Image::grayscale(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      pixel.s= 0;
    }
}
};


void Image::rotateColor(double degrees){
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++) {
        HSLAPixel & pixel = this->getPixel(x, y);
        pixel.h=pixel.h+degrees;
        if(pixel.h>360){
          pixel.h=pixel.h-360;
        }
        else if(pixel.h<0){
          pixel.h=pixel.h+360;
        }
        }
      }
  };

void Image::illinify(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel & pixel = this->getPixel(x, y);
      if ((pixel.h>=113.5)&(pixel.h<293.5)){
        pixel.h=216;
      }
      else{pixel.h=11;}
    }
  }
};

void Image::scale(double factor){
  Image *original= new Image (*this);
  resize(factor*original->width(),factor*original->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      int oldx=(int) (x*1.0/factor);
      int oldy = (int) (y*1.0/factor);
      HSLAPixel& pixel1 = original->getPixel(oldx,oldy);
      HSLAPixel& pixel2 =this->getPixel(x,y);
      pixel2=pixel1;}
    }
  delete original;
};

void Image::scale(unsigned w, unsigned h){
  Image *original= new Image (*this);
  double factor=std::min((w*1.0)/original->width(), (h*1.0)/original->height());
  resize(factor*original->width(),factor*original->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      int oldx=(int) (x*1.0/factor);
      int oldy = (int) (y*1.0/factor);
      HSLAPixel& pixel1 = original->getPixel(oldx,oldy);
      HSLAPixel& pixel2 =this->getPixel(x,y);
      pixel2=pixel1;
  }
  }
 delete original;
};
