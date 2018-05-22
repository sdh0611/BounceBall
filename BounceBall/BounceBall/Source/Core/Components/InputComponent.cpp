#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\InputComponent.h"
#include "..\..\..\Include\Scene\Object\CObject.h"


InputComponent::InputComponent()
	:ComponentBase()
{

}

void InputComponent::Init(CObject * owner)
{
	m_pOwner = owner;


}

void InputComponent::Update()
{
	//MessageBox(NULL, TEXT("Update"), TEXT("Info"), MB_ICONINFORMATION);

	if (KEY_DOWN(VK_LEFT)) {
		m_pOwner->SetObjectDirection(Types::DIR_LEFT);
	}
	else if (KEY_DOWN(VK_RIGHT)) {
		m_pOwner->SetObjectDirection(Types::DIR_RIGHT);
	}
	else {
		m_pOwner->SetObjectDirection(Types::DIR_IDLE);
	}



}
