#include "..\..\Include\Scene\CLayer.h"
#include "..\..\Include\Scene\Object\CObject.h"



CLayer::CLayer(int order, const Types::tstring & tag):
	m_iOrder(order), m_strLayerTag(tag)
{
}

CLayer::~CLayer()
{
	if(!m_ObjectList.empty())
		for (m_it = m_ObjectList.begin(); m_it != m_ObjectList.end(); ++m_it) {
			SAFE_DELETE((*m_it))
		}

	m_ObjectList.clear();

}

bool CLayer::Init()
{
	if (!m_ObjectList.empty())
		for (m_it = m_ObjectList.begin(); m_it != m_ObjectList.end(); ++m_it) {
			if (!(*m_it)->Init())
				return false;
		}


	return true;
}

void CLayer::Update()
{
	if (!m_ObjectList.empty())
		for (m_it = m_ObjectList.begin(); m_it != m_ObjectList.end(); ++m_it) {
			(*m_it)->Update();
		}
}

void CLayer::Render()
{
	if (!m_ObjectList.empty())
		for (m_it = m_ObjectList.begin(); m_it != m_ObjectList.end(); ++m_it) {
			(*m_it)->Render();
		}
}
