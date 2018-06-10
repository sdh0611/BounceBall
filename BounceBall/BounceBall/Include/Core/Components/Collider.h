#pragma once

#include "..\..\..\stdafx.h"
#include "ComponentBase.h"

//ColliderType에 Trigger도 추가해보자.

class Collider : public ComponentBase {
public:
	enum ColliderType{ CT_BOX, CT_CIRCLE, 
		CT_BOX_TRIGGER, CT_CIRCLE_TRIGGER };

public:
	Collider(CObject* owner, ColliderType type);
	virtual ~Collider();


public:
	virtual void Init() = 0;
	virtual void Update(const double& deltaTime) = 0;
	virtual void ResolveCollision(Types::ObjectType type);


public:
	const ColliderType& GetColliderType() const { return m_Type; }
	void SetColliderType(ColliderType type) { m_Type = type; }
	bool GetIsCollision() const { return m_bIsCollision; }
	void SetIsCollision(bool isCollision) { m_bIsCollision = isCollision; }


protected:
	ColliderType		m_Type;
	bool				m_bIsCollision;


private:



};