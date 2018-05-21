#pragma once


#include "..\..\stdafx.h"

class CObject;

class CLayer {

public:
	CLayer(int order, const Types::tstring& tag);
	~CLayer();


public:
	bool Init();
	void Update();
	void Render();


public:
	inline const Types::tstring& GetLayerTag() const { return m_strLayerTag; }
	inline void SetLayerTag(const Types::tstring& tag) { m_strLayerTag = tag; }
	inline int GetLayerOrder() { return m_iOrder; }
	inline void SetLayerOrder(int order) { if (order >= 0) m_iOrder = order; }


private:



private:
	int											m_iOrder;
	Types::tstring							m_strLayerTag;
	std::list<CObject*>					m_ObjectList;
	std::list<CObject*>::iterator			m_it;




};