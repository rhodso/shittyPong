//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "gameObject.h"
#include "ofMain.h"

//Constructor and Destructor
gameObject::gameObject(){}
gameObject::~gameObject(){}

//Getters and Setters
float gameObject::getX(){ return x; }
float gameObject::getY(){ return y; }
float gameObject::getX_vel(){ return x_vel; }
float gameObject::getY_vel(){ return y_vel; }
float gameObject::getDrag(){ return drag; }

void gameObject::setX( float _x){ x = _x; }
void gameObject::setY( float _y){ y = _y; }
void gameObject::setX_vel( float _x_vel){ x_vel = _x_vel; }
void gameObject::setY_vel( float _y_vel){ y_vel = _y_vel; }
void gameObject::setDrag( float _drag){ drag = _drag; }

//Other methods
void gameObject::draw(){}
void gameObject::update(){
    int h = ofGetHeight();

    //Movement control
    x_vel *= drag;
    y_vel *= drag;
    x += x_vel;
    y += y_vel;

    //Wall bounce control
    if( y < 0 ) {y=0; y_vel *= -1.0;}
    if( y>h ) {y=h; y_vel *=-1.0;}
}
