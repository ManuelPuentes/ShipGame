#ifndef BULLET_H
#define BULLET_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"
class Bullet
{
	public:
		sf::Vector2i posicion;
		sf::Vector2f director;
		int alpha;
		int weapon_origin;
		Bullet(){};
		Bullet(sf::Vector2i posicion, sf::Vector2f director,int,int);
		Bullet(sf::Vector2i posicion, sf::Vector2f director, bool,int,int);
	
	protected:
};

#endif
