#include "..\..\Include\Scene\CScene.h"
#include "..\..\Include\Scene\CLayer.h"


CScene::CScene(Types::SceneType type):
	m_SceneType(type)
{

}

CScene::~CScene()
{
	if(!m_LayerList.empty())
		for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
			SAFE_DELETE((*m_it))

		}

	m_LayerList.clear();

}

bool CScene::Init()
{
	return false;
}

void CScene::Update()
{
	if (!m_LayerList.empty())
		for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
			(*m_it)->Update();

		}

}

void CScene::Render()
{
	if (!m_LayerList.empty())
		for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
			(*m_it)->Render();


		}
}

bool CScene::CreateLayer(const Types::tstring & tag, int order)
{
	if (FindLayer(tag))
		return false;

	m_LayerList.emplace_back(new CLayer(order, tag));
	SortLayer();

	return true;
}

bool CScene::DeleteLayer(const Types::tstring & tag)
{
	if (!FindLayer(tag))
		return false;

	SAFE_DELETE((*m_it));
	m_LayerList.erase(m_it);

	return true;
}

CLayer * CScene::FindLayer(const Types::tstring & tag)
{
	for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
		if ((*m_it)->GetLayerTag() == tag)
			return (*m_it);
	}


	return nullptr;
}

bool CScene::CompareLayer(CLayer * first, CLayer * second)
{
	return (first->GetLayerOrder() < second->GetLayerOrder()); 
}
