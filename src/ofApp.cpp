#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    nodeSystem.setup(ofGetWidth(), ofGetHeight(), 20);
    midiControl.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    nodeSystem.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    nodeSystem.draw();
    ofSetColor(ofColor::red);
    ofDrawBitmapString(ofToString(ofGetFrameRate()),10, 10, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        nodeSystem.clearNodes();}
    midiControl.oneHitNote(64, 128);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    nodeSystem.moveNode(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    nodeSystem.addZone(x, y, button);
    nodeSystem.grabNode(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    nodeSystem.nodeGrabbed = 66; //randomnonZeroNumber
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
