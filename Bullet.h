#ifndef BULLET_H
#define BULLET_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Bullet
{
	public:
		sf::Vector2i posicion;
		sf::Vector2f director;
		
		sf::Sprite *sprite;
		Bullet(){};
		Bullet(sf::Texture texture, sf::Vector2i posicion, sf::Vector2f director);
	
		void Mover();
		void Draw(sf::RenderWindow &window);
	protected:
};

#endif
