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

#pragma once

#include "StepTimer.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop
class D3DApp
{
public:

	D3DApp();

	// Initialization and management
	void Initialize(HWND window, int width, int height);

	// Basic game loop
	void Tick();
	void Render();

	// Rendering helpers
	void Clear();
	void Present();

	// Messages
	void OnActivated();
	void OnDeactivated();
	void OnSuspending();
	void OnResuming();
	void OnWindowSizeChanged(int width, int height);

	// Properites
	void GetDefaultSize(int& width, int& height) const;

private:

	void Update(DX::StepTimer const& timer);

	void CreateDevice();
	void CreateResources();

	void OnDeviceLost();

	// Application state
	HWND                                            m_window;
	int                                             m_outputWidth;
	int                                             m_outputHeight;

	// Direct3D Objects
	D3D_FEATURE_LEVEL                               m_featureLevel;
	Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

	// Rendering resources
	Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
	Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>         m_depthStencil;

	// Game state
	DX::StepTimer                                   m_timer;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	DirectX::SimpleMath::Vector2 m_screenPos;
	DirectX::SimpleMath::Vector2 m_origin;

	std::unique_ptr<DirectX::CommonStates> m_states;
	RECT m_tileRect;

	RECT m_fullscreenRect;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_background;
};
#endif // D3DAPP_H