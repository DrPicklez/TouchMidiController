#ifndef FORCEZONE_H
#define FORCEZONE_H
#include "ofMain.h"


class ForceZone{
public:

    void setup(ofVec2f _position);
    void draw();
    void setNodesInBound(vector <int> nodes);
    ofVec2f getPos();
    int getRadius();
    void setForce(int _pullPush);
    int getForce();


    ofVec2f position;
    int size = 300;
    vector <int> nodesInBound;
    int nNodesInBound;
    int pullPush;

};

#endif // FORCEZONE_H
