#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"EngineApi.h"
#include"Game.h"
#include"Ventana.h"
#include"..//Dll_engine_jms/d3d9.h"
 
 class ENGINE_API Graphics
{
public:
	
	LPDIRECT3D9 pD3D;//objeto
	LPDIRECT3DDEVICE9 pd3dDevice;//device
	Graphics();
		//Ventana objVentana;
		bool Initialize(/*Ventana* _objVentana*/);
		bool Shutdown();
		void Clear();
		void Begin();
		void End();
		void Present();//manda a la pantalla lo q dibujas
//	~Graphics();

private:
//	Ventana* nuevaVentana;
	bool InitDirect3D(void);
	void Render(void);
	void CleanUp(void);
 };



#endif // !GRAPHICS_H
