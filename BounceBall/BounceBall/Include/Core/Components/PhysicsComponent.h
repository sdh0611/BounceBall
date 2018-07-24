#pragma once

#include "..\..\..\stdafx.h"
#include "..\Components\ComponentBase.h"
#include "Collider.h"
#include "ColliderBox.h"

class PhysicsComponent :public ComponentBase {
	friend void Collider::ResolveCollision(Types::ObjectType type, Collider::CollisionType collision);
	friend void ColliderBox::ResolveCollision(Types::ObjectType type, Collider::CollisionType collision);

public:
	PhysicsComponent(CObject* owner);
	virtual ~PhysicsComponent() { };


public:
	virtual void Init() override;
	virtual void Update(const double& deltaTime) override;

	
public:
	const float& GetSpeed() const { return m_fSpeed; }
	void SetSpeed(float speed) { if (speed >= 0) m_fSpeed = speed; }
	const float& GetGravity() const { return m_fGravity; }
	void SetGravity(float gravity) { if (gravity >= 0) m_fGravity = gravity; }
	const float& GetJumpForce() const { return m_fGravity; }
	void SetJumpForce(float jumpForce) { if (m_fJumpForce >= 0) m_fJumpForce = jumpForce; }

private:
	void Move(const double& deltaTime);
	void Gravity(const double& deltaTime);

	
private:
	/*
		NOTE:	������Ʈ���� ��ȣ�ۿ��� ���� ������ �޼ҵ��
	*/
	void ResetJumpForce() { m_fJumpForce = -350.f; }
	


private:
	float		m_fGravity;
	float		m_fSpeed;
	float		m_fJumpForce;



};