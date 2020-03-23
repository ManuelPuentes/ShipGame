#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics.hpp>

class Entidad
{
	public:
		sf::Vector2i posicion;
		Entidad();
		
		virtual Mover()=0;
		virtual Actualizar()=0;
		
		
		
	protected:
};

#endif
