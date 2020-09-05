#include "ofApp.h"

void ofApp::setup(){
    debugger::log("Start");
    ofSetVerticalSync(true);
    //ofBackground(0); //Where the backgound colour is set to black
    player1.setX(ofGetWidth()-20);
    player2.setX(20);
    player2.setHasReturned(true);
    p1Score = p2Score = 0;
    debugger::log("Finshed setup");
}

void ofApp::update(){
    debugger::log("Frame " + std::to_string(frameCount));
    handleKeypresses();

    b.collide(player1);
    b.collide(player2);

    b.update();
    player1.update();
    player2.update();

    player1.doAI(b);
    player2.doAI(b);

    //Scoring
    int score = b.checkScore();
    if(score == 1){
        p1Score++;
    }
    else if(score == 2){
        p2Score++;
    }
}

void ofApp::draw(){
    //ofBackground(0);
    ofSetColor(255);
    b.draw();
    player1.draw();
    player2.draw();
    ofDrawBitmapString(ofToString(p2Score) + ofToString("  ") + ofToString(p1Score) + ofToString("\n"), ofGetWidth()/2, ofGetHeight()*0.1);

    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 5);

}

void ofApp::handleKeypresses(){
    if(keys[119] && !keys[115]){
        player1.y_vel = 15.0;
        keys[119] = false;
    } else if(keys[115] && !keys[119]){
        player1.y_vel = -15.0;
        keys[115] = false;
    }

}

void ofApp::keyPressed(int key){ keys[key] = true; }


//Not used
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}

