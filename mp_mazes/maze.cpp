/* Your code here! */
#include "maze.h"
#include <queue>
using std::vector;
using std::queue;
using namespace cs225;
#include <stdlib.h>

SquareMaze::SquareMaze(){}

void SquareMaze::makeMaze(int width,int	height)
{
  width_=width;
  height_=height;
  mazeSets.addelements(width_*height_);
  rightWalls.resize(width_);
  downWalls.resize(width_);
  for(int x=0;x<width_;x++){
    rightWalls[x].resize(height_);
    downWalls[x].resize(height_);
    for(int y=0;y<height_;y++){
      rightWalls[x][y]=true;
      downWalls[x][y]=true;
    }
  }
  int numSets=width_*height_;
  while(numSets>1){
    int x=rand()%width_;
    int y=rand()%height_;
    //remove right wall
    if(rand()%2==0){
        if(x!=(width_-1)){
          if(mazeSets.find(y*width_+x)!=mazeSets.find(y*width_+x+1)){
            rightWalls[x][y]=false;
            mazeSets.setunion(y*width_+x, y*width_+x+1);
            numSets--;
          }
      }
    }
    //remove bottom wall
    else{
      if(y!=(height_-1)){
        if(mazeSets.find(y*width_+x)!=mazeSets.find((y+1)*width_+x)){
        downWalls[x][y]=false;
        mazeSets.setunion(y*width_+x,(y+1)*width_+x);
        numSets--;
        }
      }
    }
  }
}

bool 	SquareMaze::canTravel(int x, int y, int dir) const{
  switch (dir) {
    case 0: return rightWalls[x][y]==false;
    case 1: return downWalls[x][y]==false;
    case 2: return (x>0)&&rightWalls[x-1][y]==false;
    case 3: return (y>0)&&downWalls[x][y-1]==false;
  }
  return false;
}

void 	SquareMaze::setWall (int x, int y, int dir, bool exists){
  switch (dir) {
    case 0: rightWalls[x][y]=exists;
    break;
    case 1: downWalls[x][y]=exists;
    break;
  }
}

vector<int> SquareMaze::solveMaze(){
  queue<int> bfs;
  vector<int> prev;
  vector<int> distance;
  int curr,x,y;
  curr=0;
  bfs.push(0);
  for(int i=0;i<(width_*height_);i++){
    prev.push_back(-1);
    distance.push_back(0);
  }
  prev[0]=0;
  while(!bfs.empty()){
    curr=bfs.front();
    bfs.pop();
    x=curr%width_;
    y=curr/width_;
    if(canTravel(x,y,0)&&(prev[curr+1]==-1)){
      bfs.push(curr+1);
      prev[curr+1]=curr;
      distance[curr+1]=distance[curr]+1;
    }
    if(canTravel(x,y,1)&&(prev[curr+width_]==-1)){
      bfs.push(curr+width_);
      prev[curr+width_]=curr;
      distance[curr+width_]=distance[curr]+1;
    }
    if(canTravel(x,y,2)&&(prev[curr-1]==-1)){
      bfs.push(curr-1);
      prev[curr-1]=curr;
      distance[curr-1]=distance[curr]+1;
    }
    if(canTravel(x,y,3)&&(prev[curr-width_]==-1)){
      bfs.push(curr-width_);
      prev[curr-width_]=curr;
      distance[curr-width_]=distance[curr]+1;
    }
  }
  int destination=width_*(height_-1);
  for(int k=1;k<width_;k++){
    if(distance[width_*(height_-1)+k]>distance[destination]){
      destination=width_*(height_-1)+k;
    }
  }
  vector<int> solution;
  curr=destination;
  while(curr>0){
    if(prev[curr]==curr-1){
      solution.push_back(0);
    }
    else if(prev[curr]==curr-width_){
      solution.push_back(1);
    }
    else if(prev[curr]==curr+1){
      solution.push_back(2);
    }
    else if(prev[curr]==curr+width_){
      solution.push_back(3);
    }
    curr=prev[curr];
  }
  reverse(solution.begin(),solution.end());
  return solution;
}

PNG * SquareMaze::drawMaze() const{
  int newWidth=width_*10+1;
  int newHeight=height_*10+1;
  PNG* picture=new PNG(newWidth,newHeight);
  //left most column
  for(int y=0;y<newHeight;y++){
    HSLAPixel& p=picture->getPixel(0,y);
    p.l=0.0;
  }
  //top row
  for(int x=10;x<newWidth;x++){
    HSLAPixel& p=picture->getPixel(x,0);
    p.l=0.0;
  }
  for(int x=0;x<width_;x++){
    for(int y=0;y<height_;y++){
      if(rightWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel((x+1)*10,y*10+k);
          p.l=0.0;
        }
      }
      if(downWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel(x*10+k,(y+1)*10);
          p.l=0.0;
        }
      }
    }
  }
  return picture;
}

PNG * SquareMaze::drawMazeWithSolution (){
  PNG* picture=drawMaze();
  vector<int> solution=solveMaze();
  int curr_x=5;
  int curr_y=5;
  for(size_t i=0;i<solution.size();i++){
    switch (solution[i]) {
      case 0:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x+k,curr_y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_x+=10;
      break;
      case 1:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x,curr_y+k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_y+=10;
      break;
      case 2:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x-k,curr_y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_x-=10;
      break;
      case 3:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x,curr_y-k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_y-=10;
      break;
    }
  }
  int des_x=curr_x-5;
  int des_y=curr_y+5;
  for(int k=1;k<=9;k++){
    HSLAPixel& pixel=picture->getPixel(des_x+k,des_y);
    pixel.l=1;
  }
  return picture;
}

PNG* SquareMaze::drawCreativeMaze() {
  int newWidth=width_*10+1;
  int newHeight=height_*10+1;
  PNG* picture=new PNG(newWidth,newHeight);
  for(int y=0;y<int(newHeight/4.0);y++){
    HSLAPixel &pixel=picture->getPixel(0,y);
    pixel.l=0;
  }
  for(int y=int(newHeight*3/4.0);y<newHeight;y++){
    HSLAPixel &pixel=picture->getPixel(0,y);
    pixel.l=0;
  }
  for(int x=10;x<newWidth;x++){
    HSLAPixel &pixel=picture->getPixel(x,0);
  }
  for(int x=0;x<width_;x++){
    for(int y=0;y<int(height_/4.0);y++){
      if(rightWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel((x+1)*10,y*10+k);
          p.l=0.0;
        }
      }
      if(downWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel(x*10+k,(y+1)*10);
          p.l=0.0;
        }
      }
    }
  }
  for(int x=0;x<width_;x++){
    for(int y=int(height_*3/4.0);y<height_;y++){
      if(rightWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel((x+1)*10,y*10+k);
          p.l=0.0;
        }
      }
      if(downWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel(x*10+k,(y+1)*10);
          p.l=0.0;
        }
      }
    }
  }
  for(int x=int(width_/4.0);x<int(width_*3/4.0);x++){
    for(int y=int(height_/4.0);y<int(height_*3/4.0);y++){
      if(rightWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel((x+1)*10,y*10+k);
          p.l=0.0;
        }
      }
      if(downWalls[x][y]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p=picture->getPixel(x*10+k,(y+1)*10);
          p.l=0.0;
        }
      }
    }
  }
  return picture;
}

PNG* SquareMaze::drawCreativeMazeWithSolution(){
  PNG* picture=drawCreativeMaze();
  vector<int> solution=solveMaze();
  int curr_x=5;
  int curr_y=5;
  for(size_t i=0;i<solution.size();i++){
    switch (solution[i]) {
      case 0:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x+k,curr_y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_x+=10;
      break;
      case 1:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x,curr_y+k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_y+=10;
      break;
      case 2:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x-k,curr_y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_x-=10;
      break;
      case 3:
      for(int k=0;k<=10;k++){
        HSLAPixel& pixel=picture->getPixel(curr_x,curr_y-k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        pixel.a=1;
      }
      curr_y-=10;
      break;
    }
  }
  int des_x=curr_x-5;
  int des_y=curr_y+5;
  for(int k=1;k<=9;k++){
    HSLAPixel& pixel=picture->getPixel(des_x+k,des_y);
    pixel.l=1;
  }
  return picture;
}
