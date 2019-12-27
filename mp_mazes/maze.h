/* Your code here! */
#pragma once
#include "dsets.h"
#include <vector>
#include "cs225/PNG.h"
using namespace cs225;
using std::vector;

class SquareMaze{
public:
  SquareMaze();
  void makeMaze(int width,int	height);
  bool 	canTravel(int x, int y, int dir) const ;
  void 	setWall (int x, int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG * drawMaze()	const;
  PNG * drawMazeWithSolution ();
  PNG* drawCreativeMaze();
  PNG* drawCreativeMazeWithSolution();
private:
  vector<vector<bool>> rightWalls;
  vector<vector<bool>> downWalls;
  int width_;
  int height_;
  DisjointSets mazeSets;
};
