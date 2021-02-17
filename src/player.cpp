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
    batWidth = 10.0;
    batSize = 100.0;
    debugger::log("Created player");
}
player::~player(){}

//Getters and Setters
float player::getBatWidth(){ return batWidth; }
float player::getBatSize(){ return batSize; }
int player::getAiFramecount(){ return aiFramecount; }

void player::setBatWidth( float _batWidth){ batWidth = _batWidth; }
void player::setBatSize( float _batSize){ batSize = _batSize; }
void player::setAiFramecount( int _aiFramecount){ aiFramecount = _aiFramecount; }

//Other methods
void player::draw(){
    ofSetColor(255);

    //I don't know why I have to do this I just seem to have to
    ofRectangle p = ofRectangle();
    p.x = x;
    p.y = y;
    p.width = batWidth;
    p.height = batSize;

    ofDrawRectangle(p);

}
void player::update(){
    int h = ofGetHeight();

    //Movement control
    x_vel *= drag;
    y_vel *= drag;
    x += x_vel;
    y += y_vel;

    //Wall bounce control
    if( y < 0 ) {y=0; y_vel *= -1.0;}
    if( (y+batSize)>h ) {y=(h-batSize); y_vel *=-1.0;}
}
void player::doAI(gameObject g){
    if(ofDist(x,0,g.x,0) < (ofGetWidth()/2)){

        /*
         *  Formula to work out the target of where the 
         *  ball's going to land, but it doesn't take 
         *  into account wall bounces because that's FAR 
         *  too much effort. Credit to Maria for helping 
         *  me wioth maths because once I wanted to be a 
         *  maths teacher then found out that maths was 
         *  hard, so that killed that dream rather quickly
         */

        float targetY = g.y + ((ofDist(g.x, 0, x, 0)*g.y_vel)/abs(g.x_vel));
        if(y < targetY && targetY < y + batSize){ //Bat is in the right place, do nothing
            y_vel = 0;
        }
        else if(y < targetY){ //Bat is too high, move lower
            y_vel = 15.0;
        }
        else if(y > targetY){ //Bat is too low, move higher
            y_vel = -15.0;
        }
        else{ //Catch all just in case
            y_vel = 0;
        }
    }
}
