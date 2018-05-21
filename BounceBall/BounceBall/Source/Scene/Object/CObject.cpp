#include "..\..\..\Include\Scene\Object\CObject.h"
#include "..\Core\Components\ComponentBase.h"



CObject::CObject()
{
}

CObject::~CObject()
{
	if(!m_ComponentTable.empty())
		for (m_it = m_ComponentTable.begin(); m_it != m_ComponentTable.end(); ++m_it) {
			SAFE_DELETE(m_it->second)
		}

	m_ComponentTable.clear();

}

bool CObject::Init()
{
	for (m_it = m_ComponentTable.begin(); m_it != m_ComponentTable.end(); ++m_it) {
		m_it->second->Init();
	}


	return true;
}

void CObject::Update()
{
	for (m_it = m_ComponentTable.begin(); m_it != m_ComponentTable.end(); ++m_it) {
		m_it->second->Update();
	}


}

void CObject::Render()
{
	for (m_it = m_ComponentTable.begin(); m_it != m_ComponentTable.end(); ++m_it) {
		m_it->second->Render();
	}


}

ComponentBase * CObject::GetComponent(const Types::tstring & tag)
{
	m_it = m_ComponentTable.find(tag);
	if( m_it == m_ComponentTable.end())
		return nullptr;

	return m_it->second;
}

bool CObject::AddComponent(const Types::tstring & tag, ComponentBase * component)
{
	if (m_it == m_ComponentTable.end()) {
		m_ComponentTable.insert(std::make_pair(tag, component));
		return true;
	}

	return false;
}
