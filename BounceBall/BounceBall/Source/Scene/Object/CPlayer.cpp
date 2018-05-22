#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Scene\Object\CPlayer.h"
#include "..\..\..\Include\Core\Components\InputComponent.h"
#include "..\..\..\Include\Core\Components\PhysicsComponent.h"


CPlayer::CPlayer()
	:CObject(Types::OT_PLAYER) 
{

}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	//������Ʈ�� �߰�
	AddComponent(TEXT("InputComponent"), new InputComponent);
	AddComponent(TEXT("PhysicsComponent"), new PhysicsComponent);


	//������Ʈ�� �ʱ�ȭ
	CObject::Init();

	return true;
}

void CPlayer::Update()
{
	CObject::Update();

}

//�׽�Ʈ������ �ϴ� �簢�� ���
void CPlayer::Render(const HDC& hDC)
{

	Rectangle(hDC, m_fObjectPoint.x, m_fObjectPoint.y, 
		m_fObjectPoint.x + 100, m_fObjectPoint.y + 100);

}
