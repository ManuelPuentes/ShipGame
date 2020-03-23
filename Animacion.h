#ifndef ANIMACION_H
#define ANIMACION_H
#include<iostream>
#include <SFML/Graphics.hpp>

class Animacion
{
	public:
		sf::Vector2f posicion;
		
		    float Frame;
    		float animSpeed;
    		int FrameCount;
    		int pos;
    		
    		sf::Sprite sprite;
    		std::vector<sf::IntRect> frames;
		
		Animacion(){};
		
		Animacion(sf::Texture &texture,int num_fx,int num_fy,int size_x,int size_y,sf::Vector2f);
		
		void update();
		
		
	protected:
};

#endif
