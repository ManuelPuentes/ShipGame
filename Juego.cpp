#include "Juego.h"

Juego::Juego()
{

	this->window = new sf::RenderWindow(sf::VideoMode(ANCHO,ALTO),"Juego");
	int key;

    
	this->window->requestFocus();
	window->setFramerateLimit(30);
	alpha=delta=0;
	
//	director.x=1;
//	director.y=0;
	
	while(window->isOpen()){
		Mouse_Controller();
		window->clear();
    	window->draw(*nave.sprite);
    		if(kbhit()){
			key=getch();
		
		std::cout<<"tecla"<<std::endl;
	}
		window->display();	
//		std::cout<<"Hola"<<std::endl;
	}
	
	
}
void *funcion(void *arg){
	
int time=*((int*)arg);

//int i=0;
//while(i<time){
//	
//	
//	Sleep(1000);
//	std::cout<<i<<std::endl;
//	i++;
//	
//}
int key;

while(1){
	if(kbhit()){
		key=getch();
		
		std::cout<<"tecla"<<std::endl;
	}
	
}




	
}

void Juego::Iniciar(){
	
	int arg=5;
	
	if(pthread_create(&graficos,NULL,funcion,&arg)!=0);
//	pthread_join(graficos,NULL);
	
}
void Juego::Detener(){
	
}

void Juego::Mouse_Controller(){
	
	mouse_position = sf::Mouse::getPosition(*window);
	mouse_position= (sf::Vector2i)window->mapPixelToCoords(mouse_position);
	sf::Vector2f vector;
	float norma;
	int alpha =0;
	
	if(mouse_position.x>0 && mouse_position.y>0 && mouse_position.x<ANCHO && mouse_position.y<ALTO || mouse_position.x>nave.x && mouse_position.y>nave.y){
		
		
		
			std::cout<<"Primer Cuadrante"<<std::endl;
//			std::cout<<mouse_position.x <<" : "<<mouse_position.y<<std::endl;
			
			vector.x=(float)(mouse_position.x-nave.x);
			vector.y=(float)(mouse_position.y-nave.y);
			
//			std::cout<<vector.x <<" : "<<vector.y<<std::endl;
			norma=sqrt((float)pow(vector.x,2)+pow(vector.y,2));
			
			
//			std::cout<<vector.x<< " "<< norma<<std::endl;
			
			
//			vector.x= vector.x*mouse_position.x;
//			vector.x= vector.y*mouse_position.y;
			vector.x=vector.x/norma;
//			alpha=(int)((acos(vector.y)/3.1415)*180)-alpha;
			delta+=(acos(vector.x));
//			alpha=(delta/3.1415)*180;
			
			
//			std::cout<<delta<<std::endl;
			nave.sprite->setRotation(-alpha);
			if(mouse_position.x>nave.x && mouse_position.y<nave.y ||mouse_position.x<nave.x && mouse_position.y<nave.y){
				alpha=(int)( 90-((delta/3.1415)*180))-alpha;
			}else{
				alpha=(int)( 90+((delta/3.1415)*180))-alpha;
			}
//			std::cout<<(int)( 90-((delta/3.1415)*180))<<std::endl;
			std::cout<<alpha<<std::endl;
			
			delta=0;
			
			nave.sprite->setRotation(alpha);
				
//			if(delta>1){
//				
//				alpha+=(int)(delta*3);
//				delta--;
//				std::cout<<"angulo entre vectores "<<alpha<<std::endl;
//				
////				nave.sprite->setRotation(alpha);
//				
//			}	
		
	}
	
	
}

Juego::~Juego(){}



