#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\PhysicsComponent.h"
#include "..\..\..\Include\Scene\Object\CObject.h"


PhysicsComponent::PhysicsComponent() :
	ComponentBase(), m_fSpeed(0.5f), m_fGravity(0), m_fJumpForce(0)
{

}

void PhysicsComponent::Init(CObject * owner)
{
	m_pOwner = owner;
}

void PhysicsComponent::Update()
{
	Move();
	Gravity();

}


void PhysicsComponent::Move()
{
	switch (m_pOwner->GetObjectDirection()) {
	case Types::DIR_LEFT:
		//MessageBox(NULL, TEXT("LEFT"), TEXT("Info"), MB_ICONINFORMATION);
		if (m_pOwner->GetObjectPoint().x > 0)
			m_pOwner->SetObjectPointX(m_pOwner->GetObjectPoint().x - m_fSpeed);
		break;
	case Types::DIR_RIGHT:
		//MessageBox(NULL, TEXT("RIGHT"), TEXT("Info"), MB_ICONINFORMATION);
		if (m_pOwner->GetObjectPoint().x < 800)
			m_pOwner->SetObjectPointX(m_pOwner->GetObjectPoint().x + m_fSpeed);
		break;


	}

}

void PhysicsComponent::Gravity()
{

}
