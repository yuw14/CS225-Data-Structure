/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
     int numRows=theSource.getRows();
     int numColumns=theSource.getColumns();
     MosaicCanvas* result=new MosaicCanvas(numRows,numColumns);
     vector<Point<3>> tiles;
     std::map<Point<3>, size_t> map;
     tiles.resize(theTiles.size());
     for(unsigned i=0;i<theTiles.size();i++){
      LUVAPixel tilePixel=theTiles[i].getAverageColor();
      Point<3> tilePoint=convertToXYZ(tilePixel);
      tiles[i]=tilePoint;
      map.insert(std::pair<Point<3>,size_t>(tilePoint,i));
     }
     KDTree<3> TheKDTree=KDTree<3>(tiles);
     for(int x=0;x<numRows;x++){
       for(int y=0;y<numColumns;y++){
         LUVAPixel pixel=theSource.getRegionColor(x,y);
         Point<3> sourcePoint=convertToXYZ(pixel);
         Point<3> resultPoint=TheKDTree.findNearestNeighbor(sourcePoint);
         size_t index=map[resultPoint];
         result->setTile(x,y,&theTiles[index]);
       }
     }
     return result;
    // return NULL;
}
