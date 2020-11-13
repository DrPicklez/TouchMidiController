#include "midicontrol.h"
//--------------------------------------------------------------
void MidiControl::setup(){
    midiOut.setClientName("OF");
    midiOut.openVirtualPort("Balls");
    cout << midiOut.getPortName() << endl;
}
//--------------------------------------------------------------
void MidiControl::update(int millis){
    systemClock = millis;
}
//--------------------------------------------------------------
void MidiControl::oneHitNote(int note, int vel){
    RtMidiOut midiOut;
    if((midiOut.isPortOpen()) && (note > 0)){
        vector <unsigned char> midiMessage;
        midiMessage.push_back(90); //on (9...0) 'CHANNEL=0
        midiMessage.push_back(30); // note '30'
        midiMessage.push_back(127); // val 127
        midiOut.sendMessage(&midiMessage);
        midiMessage[0] = 80; //off->'8'channel0
        midiOut.sendMessage(&midiMessage);
        cout << "noteAddedToHeap" << endl;
    }
}
