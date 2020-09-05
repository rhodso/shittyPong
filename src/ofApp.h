#pragma once

#include "ofMain.h"
#include "ball.h"
#include "player.h"
#include "debugger.h"

class ofApp : public ofBaseApp{

public:
    //oF functions we're using
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    //Other methods
    void handleKeypresses();

    //Unused, but if we take them out then oF throws a hissy fit
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    bool keys[65535];       //Key array
    unsigned long long frameCount;  //Frame counter

    ball b;
    player player1;
    player player2;

    int p1Score, p2Score;
};
