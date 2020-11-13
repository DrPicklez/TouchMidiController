#ifndef STATIONARYNODE_H
#define STATIONARYNODE_H
#include "ofMain.h"

class StationaryNode{
public:
    void setup(int x, int y, int rad);
    void draw();
    float getRadius();
    ofVec2f getPosition();

    int rad, x, y;
};

#endif // STATIONARYNODE_H
