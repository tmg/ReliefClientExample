#include "ReliefClientBase.h"


//--------------------------------------------------------------
void ReliefClientBase::baseSetup(string host, int target_port, int listen_port){
	sender.setup(host, target_port);
    receiver.setup(listen_port);
}

ReliefClientBase::~ReliefClientBase() {
    ofxOscMessage m;
    m.setAddress("/relief/disconnect");
   sendToRelief(m);
}

ReliefClientBase::ReliefClientBase() {
    baseSetup(HOST,PORT,LISTEN_PORT);
}

//--------------------------------------------------------------
void ReliefClientBase::baseUpdate() {
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        messageReceived(m);
    }
    if (ofGetElapsedTimef() > lastPing + 2.f) {
        ofxOscMessage m;
        m.setAddress("/relief/heartbeat");
        m.addIntArg(LISTEN_PORT);
        sendToRelief(m);
    }
}

void ReliefClientBase::messageReceived(ofxOscMessage m) {
    printf("messageReceived not defined\n");
}

//--------------------------------------------------------------
void ReliefClientBase::sendToRelief(ofxOscMessage m) {
    sender.sendMessage(m);
}

