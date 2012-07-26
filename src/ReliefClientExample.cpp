#include "ReliefClientExample.h"


//--------------------------------------------------------------
void ReliefClientExample::setup() {
    ofBackground(40, 100, 40);
}

void ReliefClientExample::update() {
    reliefUpdate();
}

void ReliefClientExample::messageReceivedFromRelief(ofxOscMessage m) {
    if(m.getAddress() == "/relief/update") {
        printf("Relief updated\n");
    }    
}

//--------------------------------------------------------------
void ReliefClientExample::draw(){
	// display instructions
	string buf;
	buf = "Sending to " + string(RELIEF_HOST)+  ":" + ofToString(RELIEF_PORT);
	ofDrawBitmapString(buf, 10, 20);
	ofDrawBitmapString("use 0 - 9 to set the height of one pin", 10, 50);
	ofDrawBitmapString("press 'b' to send a box to the relief and 'r' to reset the relief", 10, 65);
}

//--------------------------------------------------------------
void ReliefClientExample::keyPressed(int key){    
    if(key >= '0' && key <= '9') {
        ofxOscMessage m;
        m.setAddress("/relief/set/pin");
        m.addIntArg(6);
        m.addIntArg(6);
        m.addIntArg((key-'0')*10);
        sendMessageToRelief(m);
    }
    
    if(key == 'b') {
        ofxOscMessage m;
        m.setAddress("/relief/set");
        //send the square
        for (int x = 0; x < RELIEF_SIZE_X; x++) { 
            for (int y = 0; y < RELIEF_SIZE_Y; y++) {
                if (x>2 && x < 9 && y >2 && y < 9) {
                    m.addIntArg(100);
                } else {
                    m.addIntArg(0);
                }
            }
        }
        sendMessageToRelief(m);
    }
    
    if(key == 'r') {
        ofxOscMessage m;
        m.setAddress("/relief/load");
        //rest the pins
        for (int x = 0; x < RELIEF_SIZE_X; x++) { 
            for (int y = 0; y < RELIEF_SIZE_Y; y++) {
                m.addIntArg(0);
            }
        }
        sendMessageToRelief(m);
    }
}

