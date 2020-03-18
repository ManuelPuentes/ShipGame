#include "Juego.h"

Juego::Juego()
{

	window= new sf::RenderWindow(sf::VideoMode(ANCHO,ALTO),"Juego");
	texture3.loadFromFile("bullet.png");
	bullet= new sf::Sprite(texture3);
	window->setFramerateLimit(30);
	window->requestFocus();
	alpha=delta=0;
	shooting= false;
    
	GameLoop();
	
}
void Juego::GameLoop(){
	
	while(window->isOpen()){
		
		window->clear();
		Events_controller();
		Mouse_Controller();
		
		if(shooting){
			
			bullets.push_back(Bullet(texture3,nave.orientacion,director));
			std::cout<<bullets.size()<<std::endl;		
		}
    	
    	i=bullets.begin();
    	
    	while(i!=bullets.end()){
    		bullet->setPosition((*i).posicion.x, (*i).posicion.y);
    		window->draw(*bullet);
    		
    		(*i).posicion.x+=(*i).director.x*25;
    		(*i).posicion.y+=(*i).director.y*25;
    		
    		advance(i,1);	
    		
		}
    	window->draw(*nave.sprite);
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
				
				if(sf::Mouse::Left== event.mouseButton.button)
					shooting=true;  // flag use to handle shots of the ship set true when left click is down
					
				break;
			case sf::Event::MouseButtonReleased:
				
				if(sf::Mouse::Left== event.mouseButton.button)
					shooting=false;// flag use to handle shots of the ship set false when left click is up
					
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



