#include"Graphics.h"


bool Graphics::Initialize(/*Ventana* _ventana*/) {
	//nuevaVentana = _ventana;
	if (!InitDirect3D()) {
		return false;
	}
	return true;
	
		
}
void Graphics::Begin(){
	//pd3dDevice->BeginScene();
}
void Graphics::End() {
	//pd3dDevice->EndScene();
}
void Graphics::Clear() {
	pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
}

void Graphics::Present(){
	if (NULL == pd3dDevice)
		return;

	pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
bool Graphics::Shutdown() {
	return true;
}

bool Graphics::InitDirect3D(void) {
	/*
	pD3D = NULL;
	pd3dDevice = NULL;
	//objeto dtx;
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}
	//parametros objeto direct x
	
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;
	d3dpp.hDeviceWindow = objVentana.hWnd;

	//creamos device

	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF,objVentana.hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice))) {
		return false;
	}*/
	return true;
	
	}
void Graphics::Render(void) {
	
}
void Graphics::CleanUp(void) {
	if (pd3dDevice != NULL){
		pd3dDevice->Release();
		}
		
	if (pD3D != NULL) {
		pD3D->Release();
	}
}
Graphics::Graphics() {
	
	
	

}