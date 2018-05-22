#include "..\..\stdafx.h"
#include "..\..\Include\Scene\CGameScene.h"
#include "..\..\Include\Scene\CLayer.h"
#include "..\..\Include\Scene\Object\CPlayer.h"


CGameScene::CGameScene(Types::SceneType type)
	:CScene(type)
{
}

CGameScene::~CGameScene()
{
}

bool CGameScene::Init()
{
	if (!CreateLayer(TEXT("Player"), 0))
		return false;
	FindLayer(TEXT("Player"))->AddObjectToLayer(new CPlayer);

	CScene::Init();


	return true;
}

void CGameScene::Update()
{
	CScene::Update();

}

void CGameScene::Render(const HDC& hDC)
{
	CScene::Render(hDC);

}

