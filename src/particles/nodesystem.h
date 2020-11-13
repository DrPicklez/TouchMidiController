#ifndef NODESYSTEM_H
#define NODESYSTEM_H
#include "ofMain.h"
#include "node.h"
#include "forcezone.h"
#include "midi/midicontrol.h"
#include "stationarynode.h"

class NodeSystem{

public:
    void setup(int width, int height, int nParticles);
    void draw();
    void checkForCollision(int i);
    void checkZones(int i);
    void update();
    void clearNodes();
    void addNode(int x, int y);
    void moveNode(int x, int y);
    void grabNode(int x, int y);
    void addZone(int x, int y, int state);
    void checkForCorners(int i);
    void checkStatNodes(int nNode);
    void setForcePoint(int x, int y);

    int minNodeSize, maxNodeSize, nodeSize, width, height, particleSystemSpeed;
    float flickThresh;
    vector <Node> nodes;
    int nodeGrabbed = 66;
    int particleSize;
    vector <ForceZone> zones;
    vector <StationaryNode> statNodes;
};

#endif // NODESYSTEM_H
