#pragma once

#include "..\..\..\stdafx.h"

class ComponentBase;

class CObject {
	
public:
	CObject(Types::ObjectType type, Types::Point point, Types::ObjectState state = Types::OS_IDLE,
		Types::Direction dir = Types::DIR_IDLE);
	virtual ~CObject();


public:
	virtual bool Init();
	virtual void Update(const double& deltaTime);
	virtual void Render(const HDC& hDC) = 0;


public:
	ComponentBase * GetComponent(const Types::tstring& tag);
	bool AddComponent(const Types::tstring&, ComponentBase* component);
	bool DeleteComponent(const Types::tstring& tag);


public:
	const Types::ObjectType& GetObjectType() const { return m_ObjectType; }
	void SetObjectType(Types::ObjectType type) { m_ObjectType = type; }
	const Types::ObjectState& GetObjectState() const { return m_ObjectState; }
	void SetObjectState(Types::ObjectState state) { m_ObjectState = state; }
	const Types::Direction& GetObjectDirection() const { return m_ObjectDirection; }
	void SetObjectDirection(Types::Direction dir) { m_ObjectDirection = dir; }
	const Types::Point& GetObjectPoint() const { return m_fObjectPoint; }
	void SetObjectPoint(Types::Point point) { if(point.x >= 0 && point.y >= 0) m_fObjectPoint = point; }
	void SetObjectPoint(float x, float y) { if (x>=0 && y>=0) m_fObjectPoint = { x, y }; }
	void SetObjectPointX(float x) { if (x>=0) m_fObjectPoint.x = x; }
	void SetObjectPointY(float y) { if (y>=0) m_fObjectPoint.y = y; }


protected:
	Types::ObjectType						m_ObjectType;
	Types::ObjectState						m_ObjectState;
	Types::Direction							m_ObjectDirection;
	Types::Point								m_fObjectPoint;
	typedef std::unordered_map<Types::tstring, ComponentBase*> ComponentTable;
	ComponentTable						m_ComponentTable;
	ComponentTable::iterator				m_it;


};