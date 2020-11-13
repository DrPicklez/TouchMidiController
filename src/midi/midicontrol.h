#ifndef MIDICONTROL_H
#define MIDICONTROL_H
#include "libs/RtMidi.h"
#include "ofMain.h"
//#include "ofxOsc.h"
#include "ofXml.h"

class MidiControl{
public:
    void setup();
    void update(int millis);
    void oneHitNote(int note, int vel);
    void test();

    int systemClock;
    RtMidiOut midiOut;
//    ofxOscSender sender;

};

#endif // MIDICONTROL_H
