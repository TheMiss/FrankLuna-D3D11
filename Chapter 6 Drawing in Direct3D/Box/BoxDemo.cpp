//
// Main.cpp -
//

#include "pch.h"
#include "d3dApp.h"

using namespace DirectX;
using namespace SimpleMath;


class BoxApp : public D3DApp
{
public:
	BoxApp(HINSTANCE hInstance);
	~BoxApp();

	bool Init() override;
	void OnResize() override;
	void UpdateScene(float dt) override;
	void DrawScene() override;

	void OnMouseDown(WPARAM btnState, int x, int y) override;
	void OnMouseUp(WPARAM btnState, int x, int y) override;
	void OnMouseMove(WPARAM btnState, int x, int y) override;

private:
	void BuildGeometryBuffers();
	void BuildFX();
	void BuildVertexLayout();

private:

};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	BoxApp theApp(hInstance);

	if (!theApp.Init())
		return 0;

	return theApp.Run();
}

BoxApp::BoxApp(HINSTANCE hInstance)
	: D3DApp(hInstance)
{
	mMainWndCaption = L"Box Demo";

}

BoxApp::~BoxApp()
{

}

bool BoxApp::Init()
{
	if (!D3DApp::Init())
		return false;

	BuildGeometryBuffers();
	BuildFX();
	BuildVertexLayout();

	return true;
}

void BoxApp::OnResize()
{
	D3DApp::OnResize();

}

void BoxApp::UpdateScene(float dt)
{
	
}

void BoxApp::DrawScene()
{
	//Clear(Color(0.5f, 0.5f, 0.5f, 1.0f));
	//Clear(Colors::Chocolate);
	Clear(Color(0.5f, 0.5f, 0.5f, 1.0f));


	Present();
}

void BoxApp::OnMouseDown(WPARAM btnState, int x, int y)
{
	SetCapture(mhMainWnd);
}

void BoxApp::OnMouseUp(WPARAM btnState, int x, int y)
{
	ReleaseCapture();
}

void BoxApp::OnMouseMove(WPARAM btnState, int x, int y)
{
	
}

void BoxApp::BuildGeometryBuffers()
{
	
}

void BoxApp::BuildFX()
{
	
}

void BoxApp::BuildVertexLayout()
{
	
}
