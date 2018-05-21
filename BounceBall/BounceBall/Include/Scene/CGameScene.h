#pragma once

#include "../../stdafx.h"
#include "CScene.h"



class CGameScene :public CScene {

public:
	CGameScene(Types::SceneType);
	virtual ~CGameScene();


public:
	virtual bool Init();
	virtual void Update();
	virtual void Render();


private:



private:



};