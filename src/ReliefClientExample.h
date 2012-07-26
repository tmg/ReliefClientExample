#pragma once

#include "ReliefClientBase.h"
#include "ofMain.h"
#include "ofxOsc.h"

#define RELIEF_SIZE_X 12
#define RELIEF_SIZE_Y 12

//--------------------------------------------------------
class ReliefClientExample : public ReliefClientBase {

	public:
        void setup();
		void draw();
        void update();
        void keyPressed(int key);
        virtual void reliefMessageReceived(ofxOscMessage m);
		ofTrueTypeFont font;
};

