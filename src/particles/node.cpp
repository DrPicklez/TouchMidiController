#include "node.h"

//--------------------------------------------------------------
void Node::setup(int wid, int hig, int size, float _systemSpeed){
    width = wid;
    height = hig;
    radius = size / 8;
    systemSpeed = _systemSpeed;
    position.x = int(ofRandom(radius, ofGetWidth() - radius));
    position.y = int(ofRandom(radius, ofGetHeight() - radius));

    velocity.x = ofRandom(-1, 1.);
    velocity.y = ofRandom(-1, 1.);

    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    limit = 1.;
}

//--------------------------------------------------------------
void Node::update(){
    velocity += acceleration;
    velocity.limit(limit);
    position += (velocity * systemSpeed);
}
//--------------------------------------------------------------
void Node::addForce(ofVec2f force){
    acceleration += force;
}
//--------------------------------------------------------------
ofVec2f Node::getPos(){
    return position;
}
//--------------------------------------------------------------
ofVec2f Node::getVelocity(){
    return velocity;
}
//--------------------------------------------------------------
float Node::getRadius(){
    return radius;
}
//--------------------------------------------------------------
void Node::setVelocity(ofVec2f vel){
    velocity = vel;
}
//--------------------------------------------------------------
void Node::setPosition(ofVec2f pos){
    position = pos;
}
//--------------------------------------------------------------
void Node::setLimit(float lim){
    limit = lim;
}
//--------------------------------------------------------------
void Node::setColor(ofColor col){
    color = col;
}
//--------------------------------------------------------------
void Node::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofDrawCircle(position, radius);
    ofPopStyle();
}
//--------------------------------------------------------------
void Node::setAcceleration(ofVec2f _acceleration){
    acceleration = _acceleration;
}
//--------------------------------------------------------------
ofVec2f Node::getAcceleration(){
    return acceleration;
}
//--------------------------------------------------------------
