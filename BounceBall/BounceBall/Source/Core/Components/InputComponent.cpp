#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\InputComponent.h"
#include "..\..\..\Include\Scene\Object\CObject.h"


InputComponent::InputComponent(CObject* owner)
	:ComponentBase(owner)
{

}

void InputComponent::Init()
{
	//m_pOwner = owner;


}

void InputComponent::Update(const double& deltaTime)
{
	//왠지 ObejctState에 Jump상태를 넣어놓으면 추후 
	//Damaged 상태로 전환할 떄 문제가 생길 것 같다.
	//bool형으로 따로 뺴는게 좋을듯(18.05.24)
	//if (m_pOwner->GetObjectState() != Types::OS_JUMP) {
	//	if (KEY_DOWN(VK_SPACE))
	//		m_pOwner->SetObjectState(Types::OS_JUMP);
	//}
	//else
	//	m_pOwner->SetObjectState(Types::OS_IDLE);

	KeyProcess();



}

void InputComponent::KeyProcess()
{
	//if(KEY_DOWN(VK_BACK))



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
