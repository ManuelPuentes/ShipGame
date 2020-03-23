#ifndef ENEMY1_H
#define ENEMY1_H

#include "Entidad.h"
#include "math.h"
#include <iostream>

class Enemy1 
{
	public:
		static float const DEGTORAD=0.017453f;
		static float const PI=3.141592f;
		sf::Vector2f posicion;
		int alpha;
		bool flag;
		Enemy1();
		
		Mover();
		Actualizar();
	protected:
};

#endif
