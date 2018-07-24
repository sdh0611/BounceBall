#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\PhysicsComponent.h"
#include "..\..\..\Include\Scene\Object\CObject.h"
//#include "..\..\..\Include\Core\Components\Collider.h"



PhysicsComponent::PhysicsComponent(CObject* owner) :
	ComponentBase(owner), 
	m_fSpeed(200.f), m_fGravity(1300.f), m_fJumpForce(-350.f)
{

}

void PhysicsComponent::Init()
{
	//m_pOwner = owner;
}

void PhysicsComponent::Update(const double& deltaTime)
{
	Move(deltaTime);
	Gravity(deltaTime);

}


void PhysicsComponent::Move(const double& deltaTime)
{
	switch (m_pOwner->GetObjectDirection()) {
	case Types::DIR_LEFT:
		//MessageBox(NULL, TEXT("LEFT"), TEXT("Info"), MB_ICONINFORMATION);
		if (m_pOwner->GetObjectPoint().x > 0)
			m_pOwner->SetObjectPointX(m_pOwner->GetObjectPoint().x - m_fSpeed*deltaTime);
		break;
	case Types::DIR_RIGHT:
		//MessageBox(NULL, TEXT("RIGHT"), TEXT("Info"), MB_ICONINFORMATION);
		if (m_pOwner->GetObjectPoint().x < 700)
			m_pOwner->SetObjectPointX(m_pOwner->GetObjectPoint().x + m_fSpeed * deltaTime);
		break;
	//case Types::DIR_IDLE:

	//	break;
	}

}

void PhysicsComponent::Gravity(const double& deltaTime)
{
	//점프했을 경우 일정크기의 힘 만큼 해당 Object에 힘을 가한다.
	//if (m_pOwner->GetObjectState() == Types::OS_JUMP){
		//m_pOwner->SetObjectPointY(0.5f * m_fGravity *deltaTime * deltaTime
	m_pOwner->SetObjectPointY(m_pOwner->GetObjectPoint().y + m_fJumpForce*deltaTime);

	if(m_fJumpForce < 500.f)
		m_fJumpForce += m_fGravity * deltaTime*0.75;


	//		
	//}
	//else {	
	//if (m_pOwner->GetObjectPoint().y > 400) {
	//	m_pOwner->SetObjectPointY(400.f);
	//	m_fJumpForce = -350.f;
	//}

	
	////여기서 모든 prob의 충돌에 대한 업데이트를 해야하는데, 이러면 한번밖에 안한다.
	//Collider* collider = static_cast<Collider*>(m_pOwner->GetComponent(TEXT("Collider")));
	//if (collider->GetIsCollision()) {
	//	//m_fJumpForce += m_fGravity;
	//	m_fJumpForce = -350.f;
	//}


	//if (m_pOwner->GetObjectPoint().y < 300) {
	//	m_pOwner->SetObjectPointY(m_pOwner->GetObjectPoint().y + m_fGravity * deltaTime);
	//	m_fJumpForce += m_fGravity;
	//}
}
