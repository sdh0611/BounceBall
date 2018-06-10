#pragma once

#include "../../stdafx.h"
#include "CScene.h"

//NOTE(06.10) : ���� ���� ���������鿡 ���� Ȱ���� �����ϴ� Stage Class�� �ʿ��ϴٰ� ������.

//Stage���� �θ� Ŭ���� ���� ����.
//���� ��������(06.10)
class CStage;

class CGameScene :public CScene {

public:
	CGameScene(Types::SceneType);
	virtual ~CGameScene();


public:
	virtual bool Init() override;
	virtual void Update(const double& deltaTime) override;
	virtual void Render(const HDC& hDC) override;


public:
	void CollisionDetect();


private:
	void ResetScene();		


private:
	std::unique_ptr<class CollisionDetector>	m_pCollisionDetector;
	//std::unique_ptr<CStage>						m_pCurStage;
	//std::unique_ptr<CStage>						m_pNextStage;

};