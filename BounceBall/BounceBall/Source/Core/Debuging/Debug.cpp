#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Debuging\Debug.h"

void Debug::MessageInfo(const Types::tstring& text)
{
	MessageBox(NULL, text.c_str(), TEXT("Info"), MB_ICONINFORMATION | MB_OK);

}

void Debug::MeesageError(const Types::tstring& text)
{
	MessageBox(NULL, text.c_str(), TEXT("Error"), MB_ICONERROR | MB_OK);


}
