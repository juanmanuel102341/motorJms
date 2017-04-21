#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"EngineApi.h"

#include"Ventana.h"
#include<d3d9.h>
#pragma comment(lib,"d3d9.lib")
//#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
 
 class ENGINE_API Graphics
{
public:
	
	
	Graphics();
		bool Initialize(Ventana* _objVentana);
		bool Shutdown();
		void Clear();
		void Draw();
		void Begin();
		void End();
		void Present();//manda a la pantalla lo q dibujas
//	~Graphics();

private:
	LPDIRECT3D9 pD3D;//objeto
	LPDIRECT3DDEVICE9 pd3dDevice;//device
	Ventana* nuevaVentana;
	bool InitDirect3D(void);
	void Render(void);
	void CleanUp(void);
 };



#endif // !GRAPHICS_H
