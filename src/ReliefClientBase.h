#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define RELIEF_HOST "localhost"
#define RELIEF_PORT 78746

//--------------------------------------------------------
class ReliefClientBase : public ofBaseApp {

	public:
        ReliefClientBase();
        ~ReliefClientBase();
		void reliefSetup(string host, int port);
		void reliefUpdate();
    
        virtual void messageReceivedFromRelief(ofxOscMessage m);
        void sendMessageToRelief(ofxOscMessage m);
    
		ofxOscSender reliefSender;
        ofxOscReceiver reliefReceiver;
    
        float lastHearbeat;

};

