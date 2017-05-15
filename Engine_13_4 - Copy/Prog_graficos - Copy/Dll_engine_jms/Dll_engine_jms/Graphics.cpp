#include"Graphics.h"

bool Graphics::Initialize(Ventana* _ventana) {
	nuevaVentana = _ventana;
	if (!InitDirect3D()) {
		return false;
	}
	//SetupVertexBuffer();
	//Render();
	return true;
	
		
}

HRESULT Graphics::SetupVertexBuffer(CustomVertex _coleccionVertices,int _cantidad) {
	buffer_vertex = NULL;
	HRESULT hr;

	hr = dispositivo->CreateVertexBuffer(_cantidad * sizeof(CustomVertex), 0, D3DFVF_XYZRHW | D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &buffer_vertex, NULL);
		
	//chequeo
	if (FAILED(hr)) {
		return NULL;
	}

	VOID* punterosVacios;

	hr = buffer_vertex->Lock(0, 0, (VOID**)&punterosVacios, 0);

	if (FAILED(hr)) {
		return NULL;
	}
	memcpy(punterosVacios, &_coleccionVertices, sizeof(_coleccionVertices));
	buffer_vertex->Unlock();
	return S_OK;


}



bool Graphics::MatrizTransformacion() {
	//generamos la matriz de transformacion
	HRESULT hr;
	D3DXMATRIX m_transformacion;
	D3DXMatrixIdentity(&m_transformacion);
	//D3DXMatrixMultiply(&m_transformacion, &MatrizTraslacion(), &MatrizRotacion());
	hr=dispositivo->SetTransform(D3DTS_WORLD, &m_transformacion);//se la asignamos a direct x
	if (FAILED(hr)) {
		return false;
	}
	return true;
}
D3DXMATRIX Graphics::MatrizTraslacion(float _x,float _y) {
	D3DXMATRIX matTraslacion;
	 D3DXMatrixTranslation(&matTraslacion, _x, _y, 0.0f);
	 return matTraslacion;
}
D3DXMATRIX Graphics::MatrizRotacion(float _angle) {
	D3DXMATRIX matRotacion;
	D3DXMatrixRotationZ(&matRotacion, _angle);
	return matRotacion;
}
D3DXMATRIX Graphics::MatrizScala(float _x,float _y) {
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, _x, _y,0.0f);
	return matScale;
}
bool Graphics::MatrizVista() {
	HRESULT hr;

//	D3DVIEWPORT9 viewport;
	//hr = dispositivo->GetViewport(&viewport);
	if (FAILED(hr)) {
		return false;
	}

	D3DXMATRIX m_vista;
	D3DXVECTOR3 pos(0.0f, -15.0f, 0.0f);//pos
	D3DXVECTOR3 orientacion(0.0f, 0.0f, 0.0f);//donde mira
	D3DXVECTOR3 up(0.0f, 1.0f,0.0f);//arriba
	D3DXMatrixLookAtLH(&m_vista, &pos, &orientacion, &up);//generamos la matriz
	hr=dispositivo->SetTransform(D3DTS_VIEW, &m_vista);//aaplicamos a direct x
	if (FAILED(hr)) {
		return false;
	}
	return true;
}
bool Graphics::MatrizProyeccion(){
	HRESULT hr;
	D3DXMATRIX m_proyeccion;
	D3DXMatrixOrthoLH(&m_proyeccion, nuevaVentana->ancho, nuevaVentana->alto, 1.0f, 500.0f);
	hr=dispositivo->SetTransform(D3DTS_PROJECTION, &m_proyeccion);//aplicamos dtx
	if (FAILED(hr)) {
		return false;
	}
	return true;

}
void Graphics::Draw() {
//dibujo escena
}
void Graphics::Begin(){
	dispositivo->BeginScene();
}
void Graphics::End() {
	dispositivo->EndScene();
}
void Graphics::Clear() {
	dispositivo->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
}

void Graphics::Present(){
	if (NULL == dispositivo)
		return;

	dispositivo->Present(NULL, NULL, NULL, NULL);
}
bool Graphics::Shutdown() {
	return true;
}

bool Graphics::InitDirect3D(void) {
	
	pD3D = NULL;
	dispositivo = NULL;
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
	d3dpp.hDeviceWindow = nuevaVentana->hWnd;

	//creamos device

	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF,nuevaVentana->hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dispositivo))) {
		return false;
	}
	return true;
	
	}
void Graphics::Render(void) {
	
	
	Clear();

	Begin();

	MatrizTransformacion();
	MatrizVista();
	MatrizProyeccion();

	dispositivo->SetStreamSource(0, buffer_vertex, 0, sizeof(CustomVertex));//vertex buffer
	dispositivo->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);//data de los vertices 
	
	dispositivo->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 1);//dibujo contenido del vertex

	End();
	
	Present();
}
void Graphics::CleanUp(void) {
      if (dispositivo != NULL){
		dispositivo->Release();
		}
	

	if (pD3D != NULL) {
		pD3D->Release();
	}
}
Graphics::Graphics() {
	
	
	

}