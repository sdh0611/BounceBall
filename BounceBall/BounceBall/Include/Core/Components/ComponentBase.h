//������Ʈ���� ��ӹ��� �ֻ��� �߻�Ŭ���� ����

#pragma once

#include "..\..\..\stdafx.h"

class CObject;

class ComponentBase {

public:
	ComponentBase(CObject* owner) : m_pOwner(owner) { };
	virtual ~ComponentBase() { };

	
public:
	virtual void Init() = 0;
	virtual void Update(const double& deltaTime) = 0;


public:
	inline CObject* GetOwner() { return m_pOwner; }
	inline void SetOwner(CObject* owner) { m_pOwner = owner; }
	inline const Types::tstring& GetComponentTag() const { return m_strComponentTag; }
	inline void SetComponentName(const Types::tstring& tag) { m_strComponentTag = tag; }


protected:
	Types::Point				m_Point;
	Types::tstring			m_strComponentTag;
	CObject*					m_pOwner;

};