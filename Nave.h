#ifndef NAVE_H
#define NAVE_H
//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Nave
{
	public:
		sf::Sprite *sprite;
		sf::Texture texture;
		sf::Texture texture2;
		sf::Vector2i orientacion;
		
		int x;
		int y;
		Nave(){
			
			    if (!texture.loadFromFile("nave.png")){
			    	//std::cout<<"error en la carga de imagen ";
			}
			texture2.loadFromFile("bullet.png");
			x=400;y=300;
			sprite= new sf::Sprite(texture);
			sprite->scale(.5,.5);
			sprite->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
			orientacion.x=400;
			orientacion.y=300;
			sprite->setPosition(x,y);
			
		}
		
		void shoot(sf::Vector2i posicion,sf::Vector2i director);
		void actualizar(Bullet bullet);
		void Draw(sf::RenderWindow &window);
		
		
		
	protected:
};

#endif
