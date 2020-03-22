#include "Juego.h"

Juego::Juego()
{

	window= new sf::RenderWindow(sf::VideoMode(ANCHO,ALTO),"Juego");
	window->setFramerateLimit(30);
	window->requestFocus();
	alpha=delta=0;
	con=30;
	shooting= false;
	mouse_flag=false;
    
	GameLoop();
	
}
void Juego::GameLoop(){
	
	while(window->isOpen()){
		window->clear();
		Events_controller();
//		Mouse_Controller();
				
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))nave.Mover('W');
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))nave.Mover('S');
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))nave.Mover('D');
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))nave.Mover('A');		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			
					shootRoutine();
		} 		
		
		
		nave.Draw(*window);
		nave.actualizar();
    	window->draw(*nave.sprite);
		window->display();
 }
}
void Juego::Events_controller(){
	
	while(window->pollEvent(event)){
			
			if(event.type==sf::Event::Closed){
				
				window->close();exit(1);	
			}
			if(event.type == sf::Event::MouseEntered)  mouse_flag=true; 			
			if(event.type == sf::Event::MouseLeft)  mouse_flag=false;
			
			if(event.key.shift){
				(nave.weapon==0)?nave.weapon=1: nave.weapon=0;
				con=30;
			} 			
	}	
}
void Juego::Mouse_Controller(){
	
	mouse_position = sf::Mouse::getPosition(*window);
	mouse_position= (sf::Vector2i)window->mapPixelToCoords(mouse_position);
	sf::Vector2f vector;
	float norma;
	int alpha =0;
	
	if(mouse_flag){
			
			vector.x=(float)(mouse_position.x-nave.orientacion.x);
			vector.y=(float)(mouse_position.y-nave.orientacion.y);
			norma=sqrt((float)pow(vector.x,2)+pow(vector.y,2));
			vector.x=vector.x/norma;
			vector.y=vector.y/norma;
			delta+=(acos(vector.x));
			director=(sf::Vector2f)vector;
			
//			nave.sprite->setRotation(-alpha);
			
			if(mouse_position.x>nave.orientacion.x && mouse_position.y<nave.orientacion.y ||mouse_position.x<nave.orientacion.x && mouse_position.y<nave.orientacion.y){
				alpha=(int)( 90-((delta/3.1415)*180))-alpha;
			}else{
				alpha=(int)( 90+((delta/3.1415)*180))-alpha;
			}
			delta=0;
			nave.sprite->setRotation(alpha);			
	}
}
void Juego::shootRoutine(){
	if(nave.weapon==1){
		if(nave.flag){
			nave.shoot();
			con++;
			if(con%3==0){
				nave.flag=!nave.flag;
				con=0;
					}
			}else{
				con++;
				if(con>=5){
				nave.flag=!nave.flag;
				con=0;
				}
			}						
	}else{
		if(con>=20){
			nave.shoot();
			con=0;
		}	
		con++;
	}		
}
Juego::~Juego(){}



