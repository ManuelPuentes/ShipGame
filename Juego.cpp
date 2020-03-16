#include "Juego.h"

Juego::Juego()
{

	this->window = new sf::RenderWindow(sf::VideoMode(ANCHO,ALTO),"Juego");
	if(!texture3.loadFromFile("bullet.png"))std::cout<<":C"<<std::endl;
	bullet= new sf::Sprite(texture3);
    
	this->window->requestFocus();
	window->setFramerateLimit(30);
	alpha=delta=0;
	
	
	GameLoop();
	
	
}
void Juego::GameLoop(){
	Bullet aux;
	
	while(window->isOpen()){
		
		window->clear();
		Events_controller();
		Mouse_Controller();
    	window->draw(*nave.sprite);
    	for(int i=0;i<bullets.getTam();i++){
    		
    		bullets.getTope(aux);
    		if(!(aux.posicion.x==0 && aux.posicion.y==0)){
    			bullet->setPosition(aux.posicion.x, aux.posicion.y);    		
    			window->draw(*bullet);
    			
			}
    		bullet->move(aux.director);
    		aux.posicion.x +=aux.director.x*25;
    		aux.posicion.y +=aux.director.y*25;
    		bullets.InsertarFinal(aux);	
		}
		window->display();	
 }
}

void Juego::Events_controller(){
	
	while(window->pollEvent(event)){
		
		switch(event.type){
			
			case sf::Event::Closed:
				
				window->close();
				exit(1);
				break;
				
			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					
					if(!(nave.orientacion.x==0 && nave.orientacion.y==0 || director.x==0 && director.y==0)){
						
						bullets.InsertarFinal(Bullet(texture3,nave.orientacion,director));
					}
					
				}
				
				break; 	
			default :
				break;	
		}
	}
	
}

void Juego::Mouse_Controller(){
	
	mouse_position = sf::Mouse::getPosition(*window);
	mouse_position= (sf::Vector2i)window->mapPixelToCoords(mouse_position);
	sf::Vector2f vector;
	float norma;
	int alpha =0;
	
	if(mouse_position.x>0 && mouse_position.y>0 && mouse_position.x<ANCHO && mouse_position.y<ALTO || mouse_position.x>nave.x && mouse_position.y>nave.y){
			
			vector.x=(float)(mouse_position.x-nave.x);
			vector.y=(float)(mouse_position.y-nave.y);
			norma=sqrt((float)pow(vector.x,2)+pow(vector.y,2));
			vector.x=vector.x/norma;
			vector.y=vector.y/norma;
			delta+=(acos(vector.x));
			director=(sf::Vector2f)vector;
			
			nave.sprite->setRotation(-alpha);
			
			if(mouse_position.x>nave.x && mouse_position.y<nave.y ||mouse_position.x<nave.x && mouse_position.y<nave.y){
				alpha=(int)( 90-((delta/3.1415)*180))-alpha;
			}else{
				alpha=(int)( 90+((delta/3.1415)*180))-alpha;
			}
			delta=0;
			nave.sprite->setRotation(alpha);			
	}	
}

Juego::~Juego(){}



