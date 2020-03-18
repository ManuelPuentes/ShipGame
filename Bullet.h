#ifndef BULLET_H
#define BULLET_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Bullet
{
	public:
		sf::Vector2i posicion;
		sf::Vector2f director;
		Bullet(){};
		Bullet(sf::Vector2i posicion, sf::Vector2f director);
	
	protected:
};

#endif
