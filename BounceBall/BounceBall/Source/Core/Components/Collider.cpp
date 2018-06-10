#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\Collider.h"
#include "..\..\..\Include\Core\Components\PhysicsComponent.h"
#include "..\..\..\Include\Scene\Object\CObject.h"


Collider::Collider(CObject* owner, ColliderType type)
	:ComponentBase(owner), m_Type(type), m_bIsCollision(false)
{
	
}

Collider::~Collider()
{
	//Debug::MessageInfo(TEXT("Bos Destruct"));
}

//Collision을 일으킨 Object Type별로 행동 정의
void Collider::ResolveCollision(Types::ObjectType type)
{

	switch (type) {
	//case Types::OT_ENEMY:

	//	break;
	case Types::OT_PROBS:
		PhysicsComponent * physics = static_cast<PhysicsComponent*>(
			m_pOwner->GetComponent(TEXT("PhysicsComponent")));
		physics->ResetJumpForce();
		break;
	//case Types::OT_PICKUP:

	//	break;
	}



}

//void Collider::Init()
//{
//	//m_pOwner = owner;
//
//
//}
//
//void Collider::Update(const double & deltaTime)
//{
//
//
//}
