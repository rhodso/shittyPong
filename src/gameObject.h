//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//Includes
#include "ofMain.h"
#include "debugger.h"

class gameObject {
	public:
		//Constructor and Destructor
		gameObject();
		~gameObject();

		//Getters and Setters
		float getX();
		float getY();
		float getX_vel();
		float getY_vel();
		float getDrag();

		void setX( float _x );
		void setY( float _y );
		void setX_vel( float _x_vel );
		void setY_vel( float _y_vel );
		void setDrag( float _drag );

		//Other methods
        virtual void draw();
        virtual void update();

    //protected:
		//Variables
		float x;
		float y;
		float x_vel;
		float y_vel;
		float drag;

};
#endif
