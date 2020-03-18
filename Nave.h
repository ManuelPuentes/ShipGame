#ifndef NAVE_H
#define NAVE_H
//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include <iostream>
class Nave
{
	public:
		static int const  ALTO=600;
		static int const ANCHO=800;
		sf::Sprite *sprite;
		sf::Sprite *b_sprite;
		sf::Texture texture;
		sf::Texture texture2;
		sf::Vector2i orientacion;
		std::list<Bullet> bullets;
		std::list<Bullet>::iterator i;
		
		int x;
		int y;
		Nave(){
			
			texture.loadFromFile("nave.png");
			texture2.loadFromFile("bullet.png");
			x=400;y=300;
			sprite= new sf::Sprite(texture);
			b_sprite= new sf::Sprite(texture2);
			sprite->scale(.5,.5);
			sprite->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
			orientacion.x=400;
			orientacion.y=300;
			sprite->setPosition(x,y);
			
		}
		
		void shoot(sf::Vector2f director);
		void actualizar();
		void Draw(sf::RenderWindow &window);
		
		
		
	protected:
};

#endif
