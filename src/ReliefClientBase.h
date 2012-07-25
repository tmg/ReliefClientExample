#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 78746
#define LISTEN_PORT 88331

//--------------------------------------------------------
class ReliefClientBase : public ofBaseApp {

	public:
        ReliefClientBase();
        ~ReliefClientBase();
		void baseSetup(string host, int target_port, int listen_port);
		void baseUpdate();
    
        virtual void messageReceived(ofxOscMessage m);
        void sendToRelief(ofxOscMessage m);
    
		ofTrueTypeFont font;
		ofxOscSender sender;
        ofxOscReceiver receiver;
    
        float lastPing;

};

