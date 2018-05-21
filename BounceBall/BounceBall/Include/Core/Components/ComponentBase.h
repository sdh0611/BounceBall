//컴포넌트들이 상속받을 최상위 추상클래스 정의

#pragma once

#include "..\..\..\stdafx.h"

class CObject;

class ComponentBase {

public:
	ComponentBase() = default;
	virtual ~ComponentBase() = default;

	
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;


public:
	inline CObject* GetOwner() { return m_pOwner; }
	inline void SetOwner(CObject* owner) { m_pOwner = owner; }
	inline const Types::tstring& GetComponentTag() const { return m_strComponentTag; }
	inline void SetComponentName(const Types::tstring& tag) { m_strComponentTag = tag; }


protected:
	Types::tstring			m_strComponentTag;
	class CObject*			m_pOwner;

};