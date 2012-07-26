#include "ReliefClientBase.h"

//--------------------------------------------------------------
void ReliefClientBase::reliefSetup(string host, int port) {
	reliefSender.setup(host, port);
    reliefReceiver.setup(port);
}

ReliefClientBase::~ReliefClientBase() {
    ofxOscMessage m;
    m.setAddress("/relief/disconnect");
    sendMessageToRelief(m);
}

ReliefClientBase::ReliefClientBase() {
    reliefSetup(RELIEF_HOST, RELIEF_PORT);
}

//--------------------------------------------------------------
void ReliefClientBase::reliefUpdate() {
    while (reliefReceiver.hasWaitingMessages()) {
        ofxOscMessage m;
        reliefReceiver.getNextMessage(&m);
        messageReceivedFromRelief(m);
    }
    if (ofGetElapsedTimef() > lastHearbeat + 2.f) {
        ofxOscMessage m;
        m.setAddress("/relief/heartbeat");
        sendMessageToRelief(m);
    }
}

void ReliefClientBase::messageReceivedFromRelief(ofxOscMessage m) {
    cout << "received an OSC message, but messageReceived is not implemented.";
}

//--------------------------------------------------------------
void ReliefClientBase::sendMessageToRelief(ofxOscMessage m) {
    reliefSender.sendMessage(m);
}
