#pragma once

#include "..\..\stdafx.h"

class CLayer;

class CScene {

public:
	CScene(Types::SceneType);
	virtual ~CScene();


public:
	virtual bool Init();
	virtual void Update();
	virtual void Render();


public:
	bool CreateLayer(const Types::tstring& tag, int order);
	bool DeleteLayer(const Types::tstring& tag);
	CLayer* FindLayer(const Types::tstring& tag);



private:
	static bool CompareLayer(CLayer* first, CLayer* second);
	void SortLayer() { m_LayerList.sort(CompareLayer); }


private:
	Types::SceneType					m_SceneType;
	std::list<CLayer*>					m_LayerList;
	std::list<CLayer*>::iterator		m_it;

};
