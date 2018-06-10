#include "..\..\stdafx.h"
#include "..\..\Include\Scene\CSceneManager.h"
#include "..\..\Include\Scene\CScene.h"
#include "..\..\Include\Scene\CGameScene.h"


CSceneManager::CSceneManager() :m_pScene(nullptr), m_pNextScene(nullptr) { }

CSceneManager::~CSceneManager() {
	
	SAFE_DELETE(m_pScene)
	SAFE_DELETE(m_pNextScene);

}

bool CSceneManager::Init(Types::SceneType type) {

	if (m_pScene == nullptr)
		CreateScene(type);

	if (!m_pScene->Init())
		return false;

	return true;
}

void CSceneManager::Update(const double& deltaTime)
{
	m_pScene->Update(deltaTime);
}

void CSceneManager::Render(const HDC& hDC)
{
	m_pScene->Render(hDC);
}

bool CSceneManager::CreateScene(Types::SceneType type)
{
	SAFE_DELETE(m_pScene);

	switch (type) {
	case Types::ST_TITLE:

		break;
	case Types::ST_GAME:
		m_pScene = new CGameScene(type);
		break;
	case Types::ST_SELECT:

		break;
	default:
		return false;
	}



	return true;
}

bool CSceneManager::CreateNextScene(Types::SceneType type)
{
	SAFE_DELETE(m_pNextScene);

	switch (type) {
	case Types::ST_TITLE:

		break;
	case Types::ST_GAME:
		m_pScene = new CGameScene(type);
		break;
	case Types::ST_SELECT:

		break;
	default:
		return false;
	}
	
	return true;
}

bool CSceneManager::ChangeScene()
{
	if (m_pNextScene == nullptr)
		return false;

	SAFE_DELETE(m_pScene)
	m_pScene = m_pNextScene;

	m_pNextScene = nullptr;

	return true;
}
