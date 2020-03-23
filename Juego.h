#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Nave.h"
#include "Enemy1.h"
#include "math.h"

class Juego
{
	public:
		sf::RenderWindow *window;
		static int const  ALTO=600;
		static int const ANCHO=800;
		Nave nave;
		sf::Vector2i mouse_position;// variable deprecada se usa cuando la nave sigue el movimiento mouse 
		sf::Vector2f director; // variable deprecada se usa cuando la nave sigue el movimiento mouse 
		sf::Event event;
		short fps;
		bool mouse_flag;// determina cuando el cursor esta dentro o no de la aplicacion
		
		int alpha;
		float delta;// variable deprecada se usa cuando la nave sigue el movimiento mouse 
		short int con;// variable usada para gestionar el shoot routine
		
		short int  time;
		
		std::list<Enemy1>::iterator i;
				
		Juego();
		~Juego();
		void shootRoutine();
		void Events_controller();
		void Mouse_Controller();
		void GameLoop();

		
	protected:
};

#endif
