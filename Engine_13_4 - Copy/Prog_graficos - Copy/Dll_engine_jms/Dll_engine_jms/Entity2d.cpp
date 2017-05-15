#include"Entity2d.h"
//posicion//rotacion//escala

Entity2d::Entity2d(Graphics* _nGraphics) {
	newGraphics = _nGraphics;

}
void Entity2d::Draw() {
	newGraphics->Translate();

	newGraphics->Rotate();
	
	newGraphics->Scale();
}
void Entity2d::Posicion() {
	//newGraphics->dispositivo
}