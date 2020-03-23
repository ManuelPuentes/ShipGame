#include "Bullet.h"


Bullet::Bullet(sf::Vector2i posicion, sf::Vector2f director, bool lado , int alpha, int weapon){

	this->posicion=posicion;
	this->director=director;
	this->alpha= alpha;
	this->weapon_origin=weapon;
	
	if(lado){
		this->posicion.x-=35*cos(acos(director.y));
		this->posicion.y+=35*sin(asin(director.x));
//		std::cout<<posicion.x<<":"<<posicion.y<<std::endl;
	}else{
		this->posicion.x+=50*cos(acos(director.y));
		this->posicion.y-=50*sin(asin(director.x));
		

	}
	
}
Bullet::Bullet(sf::Vector2i posicion, sf::Vector2f director,int alpha , int weapon){

	this->alpha=alpha;
	this->posicion=posicion;
	this->director=director;
	this->weapon_origin=weapon;
	
}




