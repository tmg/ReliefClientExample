#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(40, 100, 40);

	// open an outgoing connection to HOST:PORT
    currentPort = PORT;
	sender.setup(HOST, currentPort);
    receiver.setup(PORT+100);
    connected = false;    
}

testApp::~testApp() {
    ofxOscMessage m;
    m.setAddress("/relief/disconnect");
    sender.sendMessage(m);
}
//--------------------------------------------------------------
void testApp::update() {
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);        
        // check for mouse moved message
        if(m.getAddress() == "/relief/connect/reply"){           
            int port = m.getArgAsInt32(0);
            sender.setup(HOST,port);
            currentPort = port;
            printf("%d\n",port);
        }
    }
    if (connected && ofGetElapsedTimef() > lastPing + 2.f) {
        ofxOscMessage m;
        m.setAddress("/relief/ping");
        sender.sendMessage(m);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	// display instructions
	string buf;
	buf = "Sending to " + string(HOST)+  ":" + ofToString(currentPort);
	ofDrawBitmapString(buf, 10, 20);
	ofDrawBitmapString("press 'c' to connect, and 'd' to disconnect", 10, 50);
	ofDrawBitmapString("use 0 - 9 to set the height of one pin", 10, 65);
	ofDrawBitmapString("press 'b' to send a box to the relief and 'r' to reset the relief", 10, 80);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){    
    if(key == 'c'){
		ofxOscMessage m;
        m.setAddress("/relief/connect");
        m.addIntArg(PORT+100);
		sender.sendMessage(m);
        lastPing = ofGetElapsedTimef();
        connected = true;
	}
    
    if(key == 'd'){
		ofxOscMessage m;
        m.setAddress("/relief/disconnect");
		sender.sendMessage(m);
        sender.setup(HOST,PORT);
        connected = false;
	}
    
    if(key >= '0' && key <= '9') {
        ofxOscMessage m;
        m.setAddress("/relief/set/pin");
        m.addIntArg(6);
        m.addIntArg(6);
        m.addIntArg((key-'0')*10);
        sender.sendMessage(m);
    }
    
    if(key == 'b') {
        ofxOscMessage m;
        m.setAddress("/relief/set");
        //send the square
        for (int x = 0; x < 12; x++) { 
            for (int y = 0; y < 12; y++) {
                if (x>2 && x < 9 && y >2 && y < 9) {
                    m.addIntArg(100);
                } else {
                    m.addIntArg(0);
                }
            }
        }
        sender.sendMessage(m);
    }
    
    if(key == 'r') {
        ofxOscMessage m;
        m.setAddress("/relief/set");
        //send the square
        for (int x = 0; x < 12; x++) { 
            for (int y = 0; y < 12; y++) {
                m.addIntArg(0);
            }
        }
        sender.sendMessage(m);
    }
}



//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

