#include "Animacion.h"

Animacion::Animacion(sf::Texture &texture, int num_fx,int num_fy,int size_x,int size_y,sf::Vector2f posicion){
	
	
	this->posicion=posicion;
	
	for(int i=0;i<size_y;i++){
		
		for(int j=0;j<size_x;j++){
			
			frames.push_back(sf::IntRect(j*64,i*64,64,64));
		}
		
	}
	Frame=0;
    animSpeed=3;
    FrameCount=16;
    pos=0;
    
    sprite.setTexture(texture);
    sprite.setOrigin(32,32);
    sprite.setPosition(posicion);
    sprite.setTextureRect(frames[pos]);
//	std::cout<<"se creo una animacion\n";
	
}

void Animacion::update(){
		Frame+=animSpeed;
		if(Frame>=FrameCount){
			
				pos++;
				if(pos<frames.size()){
					
					sprite.setTextureRect(frames[pos]);
					
				}
			 
			Frame-=FrameCount;
		}
	
}
