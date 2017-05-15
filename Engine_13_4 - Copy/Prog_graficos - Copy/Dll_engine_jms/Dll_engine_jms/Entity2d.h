#ifndef ENTITY_2D_H
#define ENTITY_2D_H
#include"EngineApi.h"
#include"Entity.h"
#include"Graphics.h"

class ENGINE_API Entity2d:Entity
{
public:
	
	//D3DMATRIX matrix;

	Graphics*newGraphics;
	Entity2d(Graphics*_ngraphics);
	void Draw();
	void Posicion();
	
	
private:

};


#endif // !ENTITY_2D_H

