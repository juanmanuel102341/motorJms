#include"Shape.h"
//array verticces


void Shape::Poligono() {
	
		coleccionVertices[0].x = 100.0f;
		coleccionVertices[0].y = 100.0f;
		coleccionVertices[0].z = 0.0f;
		coleccionVertices[0].rw = 1.0f;
		coleccionVertices[0].color = D3DCOLOR_ARGB(0, 0, 0, 0);

		coleccionVertices[1].x = 500.0f;
		coleccionVertices[1].y = 100.0f;
		coleccionVertices[1].z = 0.0f;
		coleccionVertices[1].rw = 1.0f;
		coleccionVertices[1].color = D3DCOLOR_ARGB(0, 0, 0, 0);

		coleccionVertices[2].x = 500.0f;
		coleccionVertices[2].y = 500.0f;
		coleccionVertices[2].z = 0.0f;
		coleccionVertices[2].rw = 1.0f;
		coleccionVertices[2].color = D3DCOLOR_ARGB(0, 0, 0, 0);
	
}
void Shape::Draw() {

}
Shape::Shape() {


}
