#include "stdafx.h"
#include "MainWindow.h"


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPTSTR lpszCmdLine, int nCmdShow) {

	UNREFERENCED_PARAMETER(hPreInstance);
	UNREFERENCED_PARAMETER(lpszCmdLine);


	if (!MainWindow::GetInstance()->Init(hInstance)) {
		MessageBox(NULL, TEXT("WNDCLASS Init Failed"), TEXT("Error"), MB_ICONERROR | MB_OK);
		return 0;
	}

	UINT retValue = MainWindow::GetInstance()->MessageLoop();
	MessageBox(NULL, TEXT("Main Á¾·á"), TEXT("Info"), MB_ICONINFORMATION);

	MainWindow::Destroy();

	return retValue;

}