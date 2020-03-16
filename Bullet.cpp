#include "Bullet.h"


Bullet::Bullet(sf::Texture texture, sf::Vector2i posicion, sf::Vector2f director){
	
	sprite= new sf::Sprite(texture);
	sprite->setPosition(350,250);
	this->posicion=posicion;
	this->director=director;
	
	
}

void Bullet::Mover(){
	
	posicion.x+=director.x*10;
	posicion.y+=director.y*10;
	
//	sprite->setPosition(posicion.x,posicion.y);
	
}

void Bullet::Draw(sf::RenderWindow &window){
	
	window.draw(*sprite);
	
	
}


