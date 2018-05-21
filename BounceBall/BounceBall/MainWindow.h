#pragma once

#include "stdafx.h"
#include ".\Include\Singleton.hpp"


class MainWindow : public Singleton<MainWindow>{

	DECLARE_SINGLETON(MainWindow)

public:
	bool Init(HINSTANCE, UINT width = 800, UINT height = 640);
	void Update();
	void Render();
	void GameLogic();


public:
	bool InitWndClass();
	bool MakeWindow();
	UINT MessageLoop();


private:
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


private:
	UINT								m_iWidth;
	UINT								m_iHeight;
	WNDCLASS						m_WndClass;
	HINSTANCE						m_hInstance;
	HWND							m_hWnd;
	HDC								m_hDC;
	class CSceneManager*		m_pSceneManager;



};