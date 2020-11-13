    #ifndef NODE_H
#define NODE_H
#include "ofMain.h"

class Node{

public:
    void setup(int wid, int hig, int size, float velocity);
    void update();
    void draw();

    void setVelocity(ofVec2f pos);
    void setPosition(ofVec2f vel);
    void setLimit(float lim);
    void setColor(ofColor col);
    void setAcceleration(ofVec2f acceleration);
    void addForce(ofVec2f force);

    ofVec2f getPos();
    ofVec2f getVelocity();
    float getRadius();
    ofVec2f getAcceleration();

    ofVec2f acceleration;
    ofVec2f velocity;
    ofVec2f position;
    int width, height;
    int radius;
    float limit;
    ofColor color;
    float systemSpeed;

};

#endif // NODE_H
