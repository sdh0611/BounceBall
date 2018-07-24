#include "..\..\stdafx.h"
#include "..\..\Include\Core\CollisionDetector.h"
#include "..\..\Include\Core\Components\Collider.h"
#include "..\..\Include\Core\Components\ColliderBox.h"
#include "..\..\Include\Scene\Object\CObject.h"
//#include "..\..\Include\Core\Components\ColliderCircle.h"



CollisionDetector::CollisionDetector()
{
	
}

CollisionDetector::~CollisionDetector()
{



}

void CollisionDetector::Init()
{



}

void CollisionDetector::Update(Collider * collider1, Collider * collider2)
{
	if ((collider1->GetColliderType() == Collider::CT_BOX) && (collider2->GetColliderType() == Collider::CT_BOX))
		BoxAndBox(static_cast<ColliderBox*>(collider1), static_cast<ColliderBox*>(collider2));


}

void CollisionDetector::Update(CObject * object1, CObject * object2)
{
	Collider* collider1 = static_cast<Collider*>(object1->GetComponent(TEXT("Collider")));
	Collider* collider2 = static_cast<Collider*>(object2->GetComponent(TEXT("Collider")));

	if ((collider1->GetColliderType() == Collider::CT_BOX) && (collider2->GetColliderType() == Collider::CT_BOX))
		BoxAndBox(object1, object2);


}

//
bool CollisionDetector::BoxAndBox(ColliderBox * collider1, ColliderBox * collider2)
{
	Types::Rect box1 = collider1->GetBoxSize();
	Types::Rect box2 = collider2->GetBoxSize();

	if ( (box1.right < box2.left) || (box1.left > box2.right) )
	{
		collider1->SetIsCollision(false);
		collider2->SetIsCollision(false);
		return false;
	}
	
	if ((box1.top > box2.bottom) || (box1.bottom < box2.top))
	{
		//Debug::MessageInfo(TEXT("Collision!"));
		collider1->SetIsCollision(false);
		collider2->SetIsCollision(false);
		return false;
	}

	
	collider1->SetIsCollision(true);
	collider2->SetIsCollision(true);
	//collider1->ResolveCollision();
	return true;

}

//��Ŀ������ �ٲ���� �� ������..
bool CollisionDetector::BoxAndBox(CObject * object1, CObject * object2)
{
	ColliderBox* collider1 = static_cast<ColliderBox*>(object1->GetComponent(TEXT("Collider")));
	ColliderBox* collider2 = static_cast<ColliderBox*>(object2->GetComponent(TEXT("Collider")));

	const Types::Rect& box1 = collider1->GetBoxSize();
	const Types::Rect& box2 = collider2->GetBoxSize();

	Collider::CollisionType collisionType = Collider::COLLISION_TOP;

	//�浹�� �ƴ� ����̴�.
	if ((box1.right < box2.left) || (box1.left > box2.right))
	{
		collider1->SetIsCollision(false);
		collider2->SetIsCollision(false);
		return false;
	}

	if ((box1.top > box2.bottom) || (box1.bottom < box2.top))
	{
		//Debug::MessageInfo(TEXT("Collision!"));
		collider1->SetIsCollision(false);
		collider2->SetIsCollision(false);
		return false;
	}


	//������� ������ �浹�� �Ͼ ����̴�.
	//box2�� �������� �浹 ������ �˻��Ѵ�.
	collider1->SetIsCollision(true);
	collider2->SetIsCollision(true);

	//���� Trigger�� pickup� ���� ��� �Ʒ� if���� ���õǾ�� �Ѵ�. -> ���� �߰�����(18.07.12)
	//BUG(18.07.12) : �ƿ� collider �浹������ ���Ͼ -> �ƿ� �浹�� �Ͼ ��찡 if���� �ٷ� �ɸ��µ�?
	if (box1.bottom> box2.top && box1.top < box2.bottom) {
		//side�� ���
		Debug::MessageInfo(TEXT("COLSIDE"));
		collisionType = Collider::COLLISION_SIDE;
	}
	else {
		//top�� ���
		Debug::MessageInfo(TEXT("COLTOP"));
		collisionType = Collider::COLLISION_TOP;
	}
	//else if (box1.top < box2.bottom) {
	//	//bot�� ���
	//}	
	
	collider1->ResolveCollision(object2->GetObjectType(), collisionType);
	collider2->ResolveCollision(object1->GetObjectType(), collisionType);

	return true;
}

//bool CollisionDetector::BoxAndCircle(ColliderBox * collider1, ColliderCircle * colldier2)
//{
//	return false;
//}
//
//bool CollisionDetector::CircleToCircle(ColliderCircle * collider1, ColliderCircle * colldier2)
//{
//	return false;
//}
