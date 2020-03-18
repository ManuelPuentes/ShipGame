#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Nave.h"
#include "math.h"
class Juego
{
	public:
		sf::RenderWindow *window;
		static int const  ALTO=600;
		static int const ANCHO=800;
		Nave nave;
		sf::Vector2i mouse_position; 
		sf::Vector2f director; // vector director de las balas 
		sf::Texture texture3;// textura de las balas de la nave 
		sf::Sprite *bullet;
		sf::Event event;
		
		std::list<Bullet> bullets;
		std::list<Bullet>::iterator i;
		
		bool shooting;
		
		int alpha;
		float delta;
		
		Juego();
		~Juego();
		void Events_controller();
		void Mouse_Controller();
		void GameLoop();
	protected:
};


#endif
