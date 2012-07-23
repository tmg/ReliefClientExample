#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 78746
#define LISTEN_PORT 88331

//--------------------------------------------------------
class testApp : public ofBaseApp {

	public:
        ~testApp();
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont font;
		ofxOscSender sender;
        ofxOscReceiver receiver;
    
        float lastPing;
        bool connected;
        int currentPort;

};

