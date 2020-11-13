#include "stationarynode.h"

void StationaryNode::setup(int _x, int _y, int _rad){
    x = _x;
    y = _y;
    rad = _rad;
}
void StationaryNode::draw(){
    ofSetColor(ofColor::green);
    ofDrawEllipse(x, y, rad * 2, rad * 2);
}
ofVec2f StationaryNode::getPosition(){
    return ofVec2f(x, y);
}
float StationaryNode::getRadius(){
    return rad;
}
