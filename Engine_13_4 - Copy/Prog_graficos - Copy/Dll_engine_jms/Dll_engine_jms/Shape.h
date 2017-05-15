#ifndef SHAPE_H

#define SHAPE_H
#include"EngineApi.h"
#include "Entity2d.h"
struct CustomVertex {

	float x, y, z, rw;
	DWORD color;


};
class ENGINE_API Shape:Entity2d
{
public:
	CustomVertex coleccionVertices[3];
	 Shape();
//	~ Shape();
	 void Poligono();
	void Draw();
private:

};


#endif // !SHAPE_H

