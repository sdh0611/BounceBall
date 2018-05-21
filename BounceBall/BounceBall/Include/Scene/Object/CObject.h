#pragma once

#include "..\..\..\stdafx.h"

class ComponentBase;

class CObject {
	
public:
	CObject();
	virtual ~CObject();


public:
	virtual bool Init();
	virtual void Update();
	virtual void Render();


public:
	ComponentBase * GetComponent(const Types::tstring& tag);
	bool AddComponent(const Types::tstring&, ComponentBase* component);


private:



private:
	typedef std::unordered_map<Types::tstring, ComponentBase*> ComponentTable;
	ComponentTable						m_ComponentTable;
	ComponentTable::iterator			m_it;


};