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

//물체가 움직임에 따라 CollisionBox의 좌표도 같이 이동해야함.
//아직 Offset적용 전이라 일단 해놓고, 나중에 Offset 적용할 때 수정할 것.(5.31)
void ColliderBox::Update(const double & deltaTime)
{
	//물체 위치에 따라 CollisionBox 위치이동
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
