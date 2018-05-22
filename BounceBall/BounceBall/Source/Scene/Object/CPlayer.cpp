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
	//컴포넌트들 추가
	AddComponent(TEXT("InputComponent"), new InputComponent);
	AddComponent(TEXT("PhysicsComponent"), new PhysicsComponent);


	//컴포넌트들 초기화
	CObject::Init();

	return true;
}

void CPlayer::Update()
{
	CObject::Update();

}

//테스트용으로 일단 사각형 출력
void CPlayer::Render(const HDC& hDC)
{

	Rectangle(hDC, m_fObjectPoint.x, m_fObjectPoint.y, 
		m_fObjectPoint.x + 100, m_fObjectPoint.y + 100);

}
