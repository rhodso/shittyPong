//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef BALL_H
#define BALL_H

//Includes
#include "ofMain.h"
#include "gameObject.h"
#include "player.h"
#include "debugger.h"

class ball : public gameObject{
	public:
		//Constructor and Destructor
		ball();
		~ball();

		//Getters and Setters
		float getBallSpeed();
		float getBallSize();

		void setBallSpeed( float _ballSpeed );
		void setBallSize( float _ballSize );
        //Inherited getters and setters
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
        void draw() override;
        int checkScore();
        void reset();
        bool collide( player p );

	private:
		//Variables
		float ballSpeed;
		float ballSize;

};
#endif
