#pragma once

#include "..\..\..\stdafx.h"
#include "Collider.h"


class ColliderBox : public Collider {
	
public:
	ColliderBox(CObject* owner, float left, float top, float right, float bottom);
	ColliderBox(CObject* owner, const Types::Rect& rect);
	virtual ~ColliderBox();


public:
	virtual void Init() override;
	virtual void Update(const double& deltaTime) override;
	//virtual void ResolveCollision(Types::ObjectType type, CollisionType collision) override;

public:
	const Types::Rect& GetBoxSize() const { return m_BoxSize; }
	void SetBoxSize(float left, float top, float right, float bottom) {
		m_BoxSize.left = left;
		m_BoxSize.top = top;
		m_BoxSize.right = right;
		m_BoxSize.bottom = bottom;
	}
	UINT GetProbsWidth() const { return m_iWidth; }
	void SetProbsWidth(UINT width) { if (width > 0) m_iWidth = width; }
	UINT GetProbsHeight() const { return m_iHeight; }
	void SetProbsHeight(UINT height) { if (height > 0) m_iHeight = height; }


private:


	
private:
	UINT			m_iWidth;
	UINT			m_iHeight;
	Types::Rect	m_BoxSize;



};