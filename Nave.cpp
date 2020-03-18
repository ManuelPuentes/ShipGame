#include "Nave.h"

void Nave::shoot(sf::Vector2f director){

	bullets.push_back(Bullet(orientacion,director));
}
void Nave::actualizar(){
	i=bullets.begin();
	
	while(i!=bullets.end()){
		
			(*i).posicion.x+=(*i).director.x*25;
    		(*i).posicion.y+=(*i).director.y*25;
    		
    		if((*i).posicion.x >=ANCHO  || (*i).posicion.x<0 || (*i).posicion.y >=ALTO || (*i).posicion.y <0){
    			
    			bullets.erase(i);
//    			std::cout<<"Bullet out of range was eliminated "<<std::endl;
			} 	
    		
    		advance(i,1);	
	}
}
void Nave::Draw(sf::RenderWindow &window){
	i=bullets.begin();

	while(i!=bullets.end()){
		
		b_sprite->setPosition((sf::Vector2f)(*i).posicion);
		window.draw(*b_sprite);
		advance(i,1);
	}	
}
