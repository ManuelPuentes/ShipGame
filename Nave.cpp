#include "Nave.h"

void Nave::shoot(sf::Vector2i posicion,sf::Vector2i director){
	
//	this->bullets.InsertarFinal( Bullet(texture2,posicion,director));
	std::cout<<"shoot "<<bullets.getTam()<<std::endl ;
}

void Nave::actualizar(Bullet bullet){
	for(int i=0;i<bullets.getTam();i++){
		
		bullets.getAt(bullet,i);
		bullet.Mover();
		bullets.InsertarFinal(bullet);
		bullet.Mover();
//		std::cout<<i<<std::endl;
		
	}
	
}

void Nave::Draw(sf::RenderWindow &window){


		for(int i=0;i<bullets.getTam();i++){
			
			bullets[i].Draw(window);
		}	
}
