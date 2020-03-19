#include "Nave.h"

void Nave::shoot(){
	
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
void Nave::Mover(char e){
	
	switch(e){
		
		case 'W':
			if(orientacion.y>50){
				
			orientacion.x+=director.x*10;	
			orientacion.y+=director.y*10;	
			sprite->setPosition((sf::Vector2f)orientacion);
			}
			break;
		case 'S':
			if(orientacion.y<550){
				
			orientacion.x-=director.x*10;	
			orientacion.y-=director.y*10;
			sprite->setPosition((sf::Vector2f)orientacion);
			}
			break;
		case 'D':
			(alpha>=5)?alpha-=5:alpha=355;
			director.x=(cos(alpha*DEGTORAD));
			director.y=-(sin(alpha*DEGTORAD));
			sprite->setRotation(90-alpha);
		break;
		case 'A':
			(alpha<=355)?alpha+=5: alpha=0;
			director.x=(cos(alpha*DEGTORAD));
			director.y=-(sin(alpha*DEGTORAD));
			sprite->setRotation(-(alpha-90));
		break;										
		default:
		break;
		
	}	
}

