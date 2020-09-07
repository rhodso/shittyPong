#include "ofApp.h"

void ofApp::setup(){
    debugger::setDebug(false);
    debugger::log("Start");
    ofSetVerticalSync(true);
    ofBackground(0);
    player1 = player();
    player2 = player();
    b = ball();
    b.setBallSize(15);
    //b.setDrag(1.0f);
    player1.setX(ofGetWidth()-20);
    player2.setX(20);
    p1Score = p2Score = 0;
    debugger::log("Finshed setup");
}

void ofApp::update(){
    //debugger::log("Frame " + std::to_string(frameCount));
    handleKeypresses();

    b.collide(player1);
    b.collide(player2);

    b.update();
    player1.update();
    player2.update();

    player1.doAI(b);

    //Scoring
    int score = b.checkScore();
    if(score == 1){
        p1Score++;
    }
    else if(score == 2){
        p2Score++;
    }
    frameCount++;
}

void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    b.draw();
    player1.draw();
    player2.draw();
    ofDrawBitmapString(ofToString(p2Score) + ofToString("  ") + ofToString(p1Score) + ofToString("\n"), ofGetWidth()/2, ofGetHeight()*0.1);
}

void ofApp::handleKeypresses(){
    if(keys[119] && !keys[115]){
        player2.y_vel = -15.0;
    } else if(keys[115] && !keys[119]){
        player2.y_vel = 15.0;
    }

}

void ofApp::keyPressed(int key){ keys[key] = true; }
void ofApp::keyReleased(int key){ keys[key] = false; }

//Not used
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}

