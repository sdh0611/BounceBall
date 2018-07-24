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
	//Debug::MessageInfo(TEXT("Box Destruct"));
}

//Collision�� ����Ų Object Type���� �ൿ ����
//Collision�� ������ ���� ���۵� ���� �����ؾ���(18.07.04)
void Collider::ResolveCollision(Types::ObjectType type, Collider::CollisionType collision)
{

	switch (type) {
	//case Types::OT_ENEMY:

	//	break;
	case Types::OT_PROBS:
		/*
			NOTE:
				PROBS Object�� ���鿡 �΋H���Ÿ� �ش� ���������� �̵��� �����ϰ�,
				���Ʒ��� �΋H�� ��� ���� ���ۿ� ����� ���.
		*/
		Debug::MessageInfo(TEXT("Resolve"));
		//if(m_pOwner->GetObjectPoint().x < )
		switch (collision) {
		case CollisionType::COLLISION_TOP:		//���κп� �΋H�� ��� �߷� �ʱ�ȭ
			{
				PhysicsComponent * physics = static_cast<PhysicsComponent*>(
					m_pOwner->GetComponent(TEXT("PhysicsComponent")));
				physics->ResetJumpForce();
				Debug::MessageInfo(TEXT("TOP"));
			}
			break;
		//case CollisionType::COLLISION_BOT:		//�غκп� �΋H�� ��� Y��Ʒ��� �����ϰ���.

		//	break;
		case CollisionType::COLLISION_SIDE:		//���鿡 �΋H�� ��� X����� ������ ����.
			m_pOwner->SetObjectDirection(Types::DIR_IDLE);
			Debug::MessageInfo(TEXT("SIDE"));
			break;
		}
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
