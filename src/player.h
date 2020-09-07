//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef PLAYER_H
#define PLAYER_H

//Includes
#include "ofMain.h"
#include "gameObject.h"
#include "debugger.h"

class player : public gameObject{
	public:
		//Constructor and Destructor
		player();
        player(float _x);
		~player();

		//Getters and Setters
		float getBatWidth();
		float getBatSize();
        int getAiFramecount();

		void setBatWidth( float _batWidth );
		void setBatSize( float _batSize );
        void setAiFramecount( int _aiFramecount );

		//Other methods
        void draw() override;
        void update() override;
        void doAI(gameObject g);

	private:
		//Variables
		float batWidth;
		float batSize;
        int aiFramecount;

};
#endif
