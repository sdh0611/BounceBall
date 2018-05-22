#include "stdafx.h"
#include "MainWindow.h"
#include "Include\Scene\CSceneManager.h"


MainWindow::MainWindow(): 
	m_pSceneManager(nullptr) {

}


MainWindow::~MainWindow()
{
	m_pSceneManager->Destroy();
	ReleaseDC(m_hWnd, m_hDC);
}

bool MainWindow::Init(HINSTANCE hInstance, UINT width, UINT height)
{
	m_hInstance = hInstance;
	m_iWidth = width;
	m_iHeight = height;

	if (!InitWndClass())
		return false;

	m_hDC = GetDC(m_hWnd);

	if (m_pSceneManager == nullptr)
		m_pSceneManager = CSceneManager::GetInstance();

	if (!m_pSceneManager->Init(Types::ST_GAME))
		return false;



	return true;
}


void MainWindow::Update()
{
	m_pSceneManager->Update();


}

void MainWindow::Render()
{
	m_pSceneManager->Render(m_hDC);


}

void MainWindow::GameLogic()
{
	//MessageBox(NULL, TEXT("GameLogic"), TEXT("Info"), MB_ICONINFORMATION);
	Update();
	Render();
}


bool MainWindow::InitWndClass()
{
	m_WndClass.cbClsExtra = 0;
	m_WndClass.cbWndExtra = 0;
	m_WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_WndClass.hCursor = LoadCursor(m_hInstance, IDC_ARROW);
	m_WndClass.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
	m_WndClass.hInstance = m_hInstance;
	m_WndClass.lpfnWndProc = WndProc;
	m_WndClass.lpszClassName = TEXT("MainWindow");
	m_WndClass.lpszMenuName = NULL;
	m_WndClass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&m_WndClass))
		return false;

	if (!MakeWindow())
		return false;

	return true;
}

bool MainWindow::MakeWindow() {

	this->m_hWnd = CreateWindow(TEXT("MainWindow"), TEXT("BounceBall"), WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,
		CW_USEDEFAULT, CW_USEDEFAULT, m_iWidth, m_iHeight, HWND_DESKTOP, NULL, m_hInstance, NULL);

	if (NULL == m_hWnd) {
		DWORD error = GetLastError();
		MessageBox(NULL, TEXT("CreateWindow Fail.."), TEXT("Error"), MB_ICONWARNING | MB_OK);
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	return true;

}

UINT MainWindow::MessageLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			GameLogic();

		}

	}


	return msg.wParam;
}

LRESULT MainWindow::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	switch (iMsg) {
	case WM_CREATE:
		return 0;

	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		ReleaseDC(hWnd, hDC);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}


	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

