#include "forcezone.h"
//-----------------------------------------------
void ForceZone::setup(ofVec2f _position){
    position = _position;
    size = 300;

}
//-----------------------------------------------
ofVec2f ForceZone::getPos(){
    return position;
}
//-----------------------------------------------
void ForceZone::draw(){
    ofPushStyle();

    if(pullPush == 0){
        ofSetColor(ofColor::red, 10);
    }
    else{ofSetColor(ofColor::blue, 10);}

    ofDrawEllipse(position, size, size);
    ofPopStyle();
}
//-----------------------------------------------
void ForceZone::setNodesInBound(vector <int> nodes){
    nodesInBound = nodes;
    nNodesInBound = nodesInBound.size();

}
//-----------------------------------------------
void ForceZone::setForce(int _pullPush){
    pullPush = _pullPush;
}
//-----------------------------------------------
int ForceZone::getForce(){
    return pullPush;
}
//-----------------------------------------------
int ForceZone::getRadius(){
    return size/2;
}



