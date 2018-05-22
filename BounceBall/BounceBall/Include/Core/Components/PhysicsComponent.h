#pragma once

#include "..\..\..\stdafx.h"
#include "..\Components\ComponentBase.h"


class PhysicsComponent :public ComponentBase {

public:
	PhysicsComponent();
	virtual ~PhysicsComponent() { };


public:
	virtual void Init(CObject* owner) override;
	virtual void Update() override;

	
public:
	const float& GetSpeed() const { return m_fSpeed; }
	void SetSpeed(float speed) { if (speed >= 0) m_fSpeed = speed; }
	const float& GetGravity() const { return m_fGravity; }
	void SetGravity(float gravity) { if (gravity >= 0) m_fGravity = gravity; }
	const float& GetJumpForce() const { return m_fGravity; }
	void SetJumpForce(float jumpForce) { if (m_fJumpForce >= 0) m_fJumpForce = jumpForce; }
	

private:
	void Move();
	void Gravity();


private:
	float		m_fGravity;
	float		m_fSpeed;
	float		m_fJumpForce;



};