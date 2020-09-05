//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "ball.h"


//Constructor and Destructor
ball::ball(){
    ballSpeed = 5.0;
    x=ofGetWidth()/2.0;
    y=ofGetHeight()/2.0;

    float angle;
    switch((int)ofRandom(3)){
        case 1:
            angle = atan(1)*7;
            break;
        case 2:
            angle = atan(1)*5;
            break;
        case 3:
            angle = atan(1)*3;
            break;
        default:
            angle = atan(1);
            break;
    }

    x_vel = ballSpeed * cos(angle);
    y_vel = ballSpeed * sin(angle);
}
ball::~ball(){}

//Getters and Setters
float ball::getBallSpeed(){ return ballSpeed; }
float ball::getBallSize(){ return ballSize; }

void ball::setBallSpeed( float _ballSpeed){ ballSpeed = _ballSpeed; }
void ball::setBallSize( float _ballSize){ ballSize = _ballSize; }

//Other methods
int ball::checkScore(){
    int w = ofGetWidth();
    int res = 0;
    if( x<=0 ) { //P1 scored
        res = 1;
        reset();
    }

    if( x>=w ) { //P2 scored
        res = 2;
        reset();
    }
    return res;
}
void ball::reset(){
    ballSpeed = 5.0;
    x=ofGetWidth()/2.0;
    y=ofGetHeight()/2.0;

    float angle = ofRandom(1.5708);
    angle -= 0.785398;

    x_vel = ballSpeed * cos(angle);
    y_vel = ballSpeed * sin(angle);
}
bool ball::collide( player p ){
    if(x > p.getX() && x < p.getX() + p.getBatWidth()){
        if(y>p.getY() && y < p.getY() + p.getBatSize()){

            //Invert X velocity
            x_vel = -x_vel;

            //Add Y velocity depends on how far from the middle the ball was hit
            float yOffset = ((p.getY()+p.getBatSize()) - y)/10;
            float angle = yOffset * (3.1415926/180);

            if(y_vel <= 0){
                y_vel -= sin(angle);
            }
            else{
                y_vel += sin(angle);
            }

            //Teleport the ball if it's going to get stuck
            if(x < 100){
                x = 41;
            }
            else if(x > ofGetWidth() - 100){
                x = ofGetWidth() - 41;
            }

            //Add paddle velocity
            if(x_vel <= 0){
                x_vel -= (abs(p.getY_vel())*0.2);
            }
            else{
                x_vel += (abs(p.getY_vel())*0.2);
            }

            if(y_vel <= 0){
                y_vel -= (abs(p.getY_vel())*0.2);
            }
            else{
                y_vel += (abs(p.getY_vel())*0.2);
            }

            return true;
        }
    }
    return false;
}
void ball::draw(){
    debugger::log("Drawing ball");
    ofDrawCircle(x,y,ballSize);
}

