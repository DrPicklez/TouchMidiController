#include "nodesystem.h"

//--------------------------------------------------------------
void NodeSystem::setup(int wid, int hig, int nParticles){

    width = wid;
    height = hig;
    particleSystemSpeed = 5;           //Velocity += PSS
    flickThresh = 0.1;                 //Velocity flick threshold
    particleSize = 300;

    Node nodePush;
    for( int i = 0; i < nParticles; i ++){
        nodes.push_back(nodePush);
        nodes[i].setup(width, height, particleSize, particleSystemSpeed);
    }
}
//--------------------------------------------------------------
void NodeSystem::update(){

    for(int i = 0; i < nodes.size(); i ++){
        checkZones(i);
        checkForCollision(i);
        checkForCorners(i);
        checkStatNodes(i);
        nodes[i].update();
    }
}
//--------------------------------------------------------------
void NodeSystem::draw(){

    for(int i = 0; i < nodes.size(); i++){
        nodes[i].draw();
    }
    for(int i = 0; i < zones.size(); i++){
        zones[i].draw();
    }
    for(int i = 0; i < statNodes.size(); i++){
        statNodes[i].draw();
    }
}
//--------------------------------------------------------------
void NodeSystem::checkForCorners(int i){
    float radius = nodes[i].getRadius();        /// bang wall collisons in last
    ofVec2f position = nodes[i].getPos();
    ofVec2f velocity = nodes[i].getVelocity();

    if(position.x <= radius){
        position.x = radius;
        velocity.x = velocity.x * -1;
    }
    if(position.x >= width - radius){
        position.x = width - radius;
        velocity.x = velocity.x * -1;
    }
    if(position.y <= radius){
        position.y = radius;
        velocity.y = velocity.y * -1;
    }
    if(position.y >= height - radius){
        position.y = height - radius;
        velocity.y = velocity.y * -1;
    }

    nodes[i].setVelocity(velocity);
    nodes[i].setPosition(position);
}
//--------------------------------------------------------------
void NodeSystem::checkForCollision(int i){

    float radius = nodes[i].getRadius();
    ofVec2f position = nodes[i].getPos();
    ofVec2f velocity = nodes[i].getVelocity();

    for(int j = 0; j < nodes.size(); j++){
        if(i != j){
            float crashRad = nodes[j].getRadius();
            float sumRadius = radius + crashRad;
            float sqrRadius = sumRadius * sumRadius;
            float distSqr = position.squareDistance(nodes[j].getPos());

            if (distSqr <= sqrRadius){
                nodes[i].setVelocity(nodes[j].getVelocity());
                nodes[j].setVelocity(velocity);

                ofVec2f distanceVector = nodes[j].getPos() - position;
                ofVec2f distanceVectMag = distanceVector.getNormalized();

                ofVec2f distanceCorrection = (sumRadius-distanceVectMag)/16;        //16 strange number check formula
                ofVec2f correctionVector = distanceVector.getNormalized() * distanceCorrection;
                ofVec2f positionCorrect = nodes[j].getPos() + correctionVector;
                nodes[j].setPosition(positionCorrect);
            }
        }
    }
}

//--------------------------------------------------------------
void NodeSystem::checkZones(int nNode){
    float nodeRadius = nodes[nNode].getRadius();
    ofVec2f nodePosition = nodes[nNode].getPos();

    vector <int> nodesInZone;

    ofVec2f accel;

    for(int j = 0; j < zones.size(); j++){
        float zoneRadius = zones[j].getRadius();
        ofVec2f zonePosition = zones[j].getPos();
        float sumRadius = nodeRadius + zoneRadius;
        float sqrRadius = sumRadius * sumRadius;
        float distSqr = nodePosition.squareDistance(zonePosition);

        if (distSqr <= sqrRadius){
            ofVec2f distanceVector = nodePosition - zonePosition;
            ofVec2f distanceVectMag = distanceVector.getNormalized();

            if(zones[j].getForce() == 0){
                accel += distanceVectMag;
            }
            if(zones[j].getForce() == 2){
                distanceVectMag *= -1.;
                accel += distanceVectMag;
            }
        }
    }
    accel *= 0.02;   // forceStrength
    nodes[nNode].setAcceleration(accel);

    nodesInZone.clear();
}
//--------------------------------------------------------------
void NodeSystem::checkStatNodes(int nNode){
    float nodeRadius = nodes[nNode].getRadius();
    ofVec2f nodePosition = nodes[nNode].getPos();

    for(int j = 0; j < statNodes.size(); j++){
        float statNodeRadius = statNodes[j].getRadius();
        ofVec2f statNodePosition = statNodes[j].getPosition();
        float sumRadius = nodeRadius + statNodeRadius;
        float sqrRadius = sumRadius * sumRadius;
        float distSqr = nodePosition.squareDistance(statNodePosition);

        if (distSqr <= sqrRadius){
            ofVec2f pVel = nodes[nNode].getVelocity();
            nodes[nNode].setVelocity(pVel * -1);

            ofVec2f distanceVector = nodes[nNode].getPos() - statNodePosition;
            ofVec2f distanceVectMag = distanceVector.getNormalized();

            ofVec2f distanceCorrection = (sumRadius-distanceVectMag)/16;        //16 strange number check formula
            ofVec2f correctionVector = distanceVector.getNormalized() * distanceCorrection;
            ofVec2f positionCorrect = nodes[nNode].getPos() + correctionVector;
            nodes[nNode].setPosition(positionCorrect);
        }
    }
}
//--------------------------------------------------------------
void NodeSystem::clearNodes(){
    nodes.clear();
}
//--------------------------------------------------------------
void NodeSystem::addNode(int x, int y){
    Node node;
    node.setup(width, height, particleSize , particleSystemSpeed);
    node.setPosition(ofVec2f(x, y));
    nodes.push_back(node);
}
//--------------------------------------------------------------
ofVec2f position2;
void NodeSystem::moveNode(int x, int y){

    nodes[nodeGrabbed].setVelocity(ofVec2f(0, 0));
    ofVec2f position1 = ofVec2f(x, y);
    nodes[nodeGrabbed].setPosition(position1);

    ofVec2f velocity = position1 - position2;       //add second position to node for multiple
    velocity /= particleSystemSpeed;

    if((abs(velocity.x + velocity.y)/2.) > flickThresh){
        nodes[nodeGrabbed].setVelocity(velocity);
    }
    position2 = position1;
}
//--------------------------------------------------------------
void NodeSystem::grabNode(int x, int y){
bool none = true;
    for(int i = 0; i < nodes.size(); i++){
        int xPos = nodes[i].position.x;
        int yPos = nodes[i].position.y;
        int rad = nodes[i].getRadius();

        if((x > (xPos - rad)) && (x < (xPos + rad))){
            if((y > (yPos - rad)) && (y < (yPos + rad))){
                nodeGrabbed = i;
                cout << "nNode" << i << endl;
                none = false;
            }
        }
    }
}
//--------------------------------------------------------------
void NodeSystem::addZone(int x, int y, int state){

    ForceZone zone;
    zone.setup(ofVec2f(x, y));

    if(state == 0){
        zone.setForce(0);
        zones.push_back(zone);
    }
    else if(state == 1){
        StationaryNode statNode;
        statNode.setup(x, y, zone.getRadius()/3);
        statNodes.push_back(statNode);
        zone.setForce(2);
        zones.push_back(zone);
    }
    else if(state == 2){
        zone.setForce(2);               /// FFFFFFFFIIIIIIIIIIXXXXXXXXX <-----------------
        zones.push_back(zone);
    }

}
//--------------------------------------------------------------
