#include "Enemy1.h"

Enemy1::Enemy1()
{
	posicion.x=0;
	posicion.y=0;
//	sprite->setPosition((sf::Vector2f)posicion);
	alpha=0;
	flag=true;
	
}

Enemy1::Mover(){
	
	posicion.y+=1;
	posicion.x+=7*(sin(alpha*DEGTORAD));	
	alpha+=1;

	if(alpha%90==0){
		flag=!flag;
	}
//	sprite->setPosition((sf::Vector2f)posicion);
}


