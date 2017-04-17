#include"Game.h"


bool Game::StartUp(HINSTANCE hInstance)
{

	nuevaVentana = new Ventana;
	nuevaVentana->registerClass(hInstance);

	if (!nuevaVentana->createWindow(hInstance, L"PROYECTO", nuevaVentana->ancho,nuevaVentana->alto)) {
		return false;
	}
	else {
		
		//nuevoGraphics = new Graphics(nuevaVentana);
		//if (!nuevoGraphics->Initialize()) {
		//	return false;
		//}
		return OnInitialize();
	//mensaje error
	}
}
void Game::Update() {
	static MSG	msg;			// Estructura de mensajes
	static bool	done = false;	// Si debo interrumpir el loop
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				done = true;			// ALT-F4
			
		}
		else {
			
			OnDraw();
			done = !OnLoop();
			
		}
	}

}

bool Game::ShutDown() {
	OnShutDown();
	return true;
}

bool Game::OnInitialize() {
	return true;
}
bool Game::OnLoop() {
	return true;
}
void Game::OnDraw() {
//	nuevoGraphics->Clear();
	//nuevoGraphics->Begin();
	//nuevoGraphics->End();
	//nuevoGraphics->Present();
}
bool Game::OnShutDown() {
	return true;
}
Game::Game() {


}