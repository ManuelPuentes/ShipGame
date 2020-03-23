#include "Nave.h"

void Nave::shoot(){
	sf::Vector2f director_aux;
	director_aux=director;
	int beta=0;
	
	
	switch(weapon){
		case 1:
			
			bullets.push_back(Bullet(orientacion,director,false));
			bullets.push_back(Bullet(orientacion,director,true));
			break;
			
		default:
			for(int i=0;i<30;i++){
				director_aux.x=(cos(beta*DEGTORAD));
				director_aux.y=-(sin(beta*DEGTORAD));
				beta+=12 ;
				bullets.push_back(Bullet(orientacion,director_aux));	
				
			}
			break;	
	}
}
void Nave::actualizar(){
	sf::Vector2f tilesize = sf::Vector2f(25,25);
	
	
	bool band=false;
	
	
	i=bullets.begin();
	
	while(i!=bullets.end() ){
		e=enemys.begin();
			b_sprite->setPosition((sf::Vector2f)(*i).posicion);
				
				while(e!=enemys.end()){
					sf::FloatRect tile((*e).posicion,tilesize);
			
					if(b_sprite->getGlobalBounds().intersects(tile)){
						enemys.erase(e);
						std::cout<<"se detecto una colision bullet/enemy \n";
						band=true;
						break; 
					}		
					advance(e,1);
				}
			
			
		if(!band){
			band=false;
			(*i).posicion.x+=(*i).director.x*17;
    		(*i).posicion.y+=(*i).director.y*17;
    		
    		if((*i).posicion.x >=ANCHO  || (*i).posicion.x<0 || (*i).posicion.y >=ALTO || (*i).posicion.y <0){
    			
    			bullets.erase(i);
//    			std::cout<<"Bullet out of range was eliminated "<<std::endl;
			}	
		}	
			
    		advance(i,1);	
	}
	
	e=enemys.begin();
	
	
	
	while(e!=enemys.end()){
		
		(*e).Mover();
		(*e).Mover();
		
		sf::FloatRect tile((*e).posicion,tilesize);
		if(sprite->getGlobalBounds().intersects(tile)){
			enemys.erase(e);
			std::cout<<"se detecto una colision\n"; 
		}		
		
//		sprite->getGlobalBounce().intersects();
		advance(e,1);
		
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
				
			orientacion.x+=director.x*10;	
			orientacion.y+=director.y*10;	
			sprite->setPosition((sf::Vector2f)orientacion);
			
			break;
		case 'S':
		
			orientacion.x-=director.x*10;	
			orientacion.y-=director.y*10;
			sprite->setPosition((sf::Vector2f)orientacion);
			
			break;
		case 'D':
			(alpha>=3)?alpha-=3:alpha=357;
			director.x=(cos(alpha*DEGTORAD));
			director.y=-(sin(alpha*DEGTORAD));
			sprite->setRotation(90-alpha);
		break;
		case 'A':
			(alpha<=357)?alpha+=3:alpha=0;
			director.x=(cos(alpha*DEGTORAD));
			director.y=-(sin(alpha*DEGTORAD));
			sprite->setRotation(-(alpha-90));
		break;										
		default:
		break;
		
	}	
}

