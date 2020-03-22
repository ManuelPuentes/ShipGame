#ifndef NAVE_H
#define NAVE_H
//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include <iostream>
#include <math.h>
class Nave
{
	public:
		static int const  ALTO=600;
		static int const ANCHO=800;
		static float const DEGTORAD=0.017453f;
		sf::Sprite *sprite;
		sf::Sprite *b_sprite;
		sf::Texture texture;
		sf::Texture texture2;
		sf::Vector2i orientacion;
		sf::Vector2f director;
		std::list<Bullet> bullets;
		std::list<Bullet>::iterator i;
		int alpha;
		int weapon;
		
		bool flag;
		
		Nave(){
			
			texture.loadFromFile("nave.png");
			texture2.loadFromFile("bullet.png");
			sprite= new sf::Sprite(texture);
			b_sprite= new sf::Sprite(texture2);
			sprite->scale(.4,.4);  
			b_sprite->scale(.7,.7);
			
			director.x=0;
			director.y=-1;
			
			
			sprite->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
			orientacion.x=400;
			orientacion.y=300;
			sprite->setPosition((sf::Vector2f)orientacion);
			alpha=90;
			weapon=0;
			flag=true;
		}
		
		void shoot();
		void actualizar();
		void Draw(sf::RenderWindow &window);
		void Mover(char e);
		
		
	protected:
};

#endif
