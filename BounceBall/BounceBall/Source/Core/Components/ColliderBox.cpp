#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Core\Components\ColliderBox.h"
#include "..\..\..\Include\Scene\Object\CObject.h"




ColliderBox::ColliderBox(CObject * owner, float left, float top, float right, float bottom)
	:Collider(owner, CT_BOX), m_BoxSize(Types::Rect(left, top, right, bottom)),
	m_iWidth(right - left), m_iHeight(bottom - top)
{
	//Debug::MessageInfo(TEXT("Create Box!"));
}

ColliderBox::ColliderBox(CObject * owner, const Types::Rect& rect) :
	Collider(owner, CT_BOX), m_BoxSize(rect),
	m_iWidth(rect.right - rect.left), m_iHeight(rect.bottom - rect.top)
{     
	//Debug::MessageInfo(TEXT("Create Box2!"));
	
}

ColliderBox::~ColliderBox()
{
	//Debug::MessageInfo(TEXT("Bos Destruct"));
}

void ColliderBox::Init()
{
	//Debug::MessageInfo(TEXT("Box Init"));

}

//��ü�� �����ӿ� ���� CollisionBox�� ��ǥ�� ���� �̵��ؾ���.
//���� Offset���� ���̶� �ϴ� �س���, ���߿� Offset ������ �� ������ ��.(5.31)
void ColliderBox::Update(const double & deltaTime)
{
	//��ü ��ġ�� ���� CollisionBox ��ġ�̵�
	m_BoxSize.left = m_pOwner->GetObjectPoint().x;
	m_BoxSize.top = m_pOwner->GetObjectPoint().y;
	m_BoxSize.right = m_pOwner->GetObjectPoint().x + (float)m_iWidth;
	m_BoxSize.bottom = m_pOwner->GetObjectPoint().y + (float)m_iHeight;

	if (m_bIsCollision) {
		//m_bIsCollision = false;
		//PhysicsComponent* physics = static_cast<PhysicsComponent*>(m_pOwner->GetComponent(TEXT("PhysicsPhysicsComponent")));
		//if (physics == nullptr)
		//	return;

		//physics->Update(deltaTime);
	}
	
}
