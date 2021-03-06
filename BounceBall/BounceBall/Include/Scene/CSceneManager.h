#pragma once

#include "..\..\stdafx.h"
#include "..\Singleton.hpp"


class CScene;

class CSceneManager : public Singleton<CSceneManager> {

	DECLARE_SINGLETON(CSceneManager)

public:
	bool Init(Types::SceneType type);
	void Update();
	void Render();


public:
	bool CreateScene(Types::SceneType type);
	bool CreateNextScene(Types::SceneType type);
	bool ChangeScene();


private:



private:
	CScene *		m_pScene;
	CScene*		m_pNextScene;



};