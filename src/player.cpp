//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "player.h"
#include "debugger.h"

//Constructor and Destructor
player::player(){
    x = ofGetWidth() - 20.0;
    y = ofRandom(0, ofGetHeight());
    x_vel = 0;
    y_vel = 0;
    drag = 0.9;
    hasReturned = false;
    debugger::log("Created player");
}
player::~player(){}

//Getters and Setters
float player::getBatWidth(){ return batWidth; }
float player::getBatSize(){ return batSize; }
int player::getAiFramecount(){ return aiFramecount; }
bool player::getHasReturned(){ return hasReturned; }

void player::setBatWidth( float _batWidth){ batWidth = _batWidth; }
void player::setBatSize( float _batSize){ batSize = _batSize; }
void player::setAiFramecount( int _aiFramecount){ aiFramecount = _aiFramecount; }
void player::setHasReturned( bool _hasReturned){ hasReturned = _hasReturned; }

//Other methods
void player::draw(){
    debugger::log("Drawing player");
    ofSetColor(ofColor::white);
    ofDrawRectangle(x,y,batWidth,batSize);
}
void player::doAI(gameObject g){
    if(ofDist(x,0,g.x,0) < (ofGetWidth()/2)){
        float targetY = g.y + ((ofDist(g.x, 0, x, 0)*g.y_vel)/g.x_vel);
        if(y < targetY && targetY < y + batSize){ //Bat is in the right place, do nothing
            y_vel = 0;
        }
        else if(y < targetY){ //Bat is too high, move lower
            y_vel = 15.0;
        }
        else if(y > targetY){ //Bat is too low, move higher
            y_vel = -15.0;
        }
        else{
            y_vel = 0;
        }
    }
}
