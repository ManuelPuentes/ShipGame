#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <pthread.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "Nave.h"
#include "math.h"
class Juego
{
	public:
		sf::RenderWindow *window;
		pthread_t graficos;
		static int const  ALTO=600;
		static int const ANCHO=800;
		Nave nave;
		sf::Vector2i mouse_position;
		sf::Vector2f direccion;
		int alpha;
		float delta;
		
		Juego();
		~Juego();

		
		void Iniciar();
		void Detener();
		void Mouse_Controller();
	protected:
};


#endif
