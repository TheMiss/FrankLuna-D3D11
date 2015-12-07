//***************************************************************************************
// d3dApp.h by Frank Luna (C) 2011 All Rights Reserved.
//
// Simple Direct3D demo application class.  
// Make sure you link: d3d11.lib d3dx11d.lib D3DCompiler.lib D3DX11EffectsD.lib 
//                     dxerr.lib dxgi.lib dxguid.lib.
// Link d3dx11.lib and D3DX11Effects.lib for release mode builds instead
//   of d3dx11d.lib and D3DX11EffectsD.lib.
//***************************************************************************************

#ifndef D3DAPP_H
#define D3DAPP_H

//#pragma once

//#include "pch.h"
#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0600
#include <SDKDDKVer.h>

// Use the C++ standard templated min/max
#define NOMINMAX

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "d3dUtil.h"
#include "GameTimer.h"
#include <string>

#include "StepTimer.h"
#include <DirectXMath.h>

class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance);
	virtual ~D3DApp();

	HINSTANCE AppInst()const;
	HWND      MainWnd()const;
	float     AspectRatio()const;

	int Run();

	// Framework methods.  Derived client class overrides these methods to 
	// implement specific application requirements.

	virtual bool Init();
	virtual void OnResize();
	virtual void UpdateScene(float dt) = 0;
	virtual void DrawScene() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	// Convenience overrides for handling mouse input.
	virtual void OnMouseDown(WPARAM btnState, int x, int y){ }
	virtual void OnMouseUp(WPARAM btnState, int x, int y)  { }
	virtual void OnMouseMove(WPARAM btnState, int x, int y){ }

protected:
	bool InitMainWindow();
	bool InitDirect3D();

	void CalculateFrameStats();

	virtual void CreateDevice();
	virtual void CreateResources();
	virtual void OnDeviceLost();
	void Clear(const FLOAT color[4] = DirectX::Colors::CornflowerBlue);
	void Present();

protected:

	HINSTANCE mhAppInst;
	HWND      mhMainWnd;
	bool      mAppPaused;
	bool      mMinimized;
	bool      mMaximized;
	bool      mResizing;
	UINT      m4xMsaaQuality;

	GameTimer mTimer;
	// Game state
	DX::StepTimer                                   m_timer;

	D3D_FEATURE_LEVEL                               mFeatureLevel;
	Microsoft::WRL::ComPtr<ID3D11Device>            md3dDevice;
	Microsoft::WRL::ComPtr<ID3D11Device1>			md3dDevice1;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>     md3dImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    md3dImmediateContext1;

	// Rendering resources
	Microsoft::WRL::ComPtr<IDXGISwapChain>          mSwapChain;
	Microsoft::WRL::ComPtr<IDXGISwapChain1>         mSwapChain1;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  mRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  mDepthStencilView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>         mDepthStencil;
	//ID3D11Device* md3dDevice;
	//ID3D11DeviceContext* md3dImmediateContext;
	//IDXGISwapChain* mSwapChain;
	//ID3D11Texture2D* mDepthStencilBuffer;
	//ID3D11RenderTargetView* mRenderTargetView;
	//ID3D11DepthStencilView* mDepthStencilView;
	//D3D11_VIEWPORT mScreenViewport;

	// Derived class should set these in derived constructor to customize starting values.
	std::wstring mMainWndCaption;
	D3D_DRIVER_TYPE md3dDriverType;
	int mClientWidth;
	int mClientHeight;
	bool mEnable4xMsaa;
};

#endif // D3DAPP_H