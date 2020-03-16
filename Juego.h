#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
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
		sf::Vector2f director;
		sf::Texture texture3;
		sf::Sprite *bullet;
		sf::Event event;
		Lista<Bullet> bullets;
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
