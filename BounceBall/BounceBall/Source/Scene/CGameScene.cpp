#include "..\..\stdafx.h"
#include "..\..\Include\Scene\CGameScene.h"
#include "..\..\Include\Scene\CLayer.h"
#include "..\..\Include\Scene\Object\CPlayer.h"
#include "..\..\Include\Scene\Object\CProbs.h"
#include "..\..\Include\Core\CollisionDetector.h"
#include "..\..\Include\Core\Components\Collider.h"




CGameScene::CGameScene(Types::SceneType type)
	:CScene(type), m_pCollisionDetector(nullptr)
	//,m_pCurStage(nullptr), m_pNextStage(nullptr)
{
}

CGameScene::~CGameScene()
{
}

//Layer�켱���� 0���� ���� UI�� �� ������.
bool CGameScene::Init()
{
	if(m_pCollisionDetector == nullptr)
		m_pCollisionDetector = std::make_unique<CollisionDetector>();

	if (!CreateLayer(TEXT("Player"), 1))
		return false;
	FindLayer(TEXT("Player"))->AddObjectToLayer(new CPlayer);

	
	if (!CreateLayer(TEXT("Probs"), 3))
		return false;

	FindLayer(TEXT("Probs"))->AddObjectToLayer(new CProbs(0.f, 500.f, 800.f, 600.f));
	FindLayer(TEXT("Probs"))->AddObjectToLayer(new CProbs(100.f, 400.f, 150.f, 450.f));
	FindLayer(TEXT("Probs"))->AddObjectToLayer(new CProbs(200.f, 350.f, 250.f, 400.f));
	FindLayer(TEXT("Probs"))->AddObjectToLayer(new CProbs(250.f, 300.f, 300.f, 350.f));
	FindLayer(TEXT("Probs"))->AddObjectToLayer(new CProbs(300.f, 250.f, 350.f, 300.f));


	CScene::Init();


	return true;
}

void CGameScene::Update(const double& deltaTime)
{
	//Scene������ ��ü�鳢�� �浹 �˻�
	//Bug(06.09) : �������� prob�� �߰��ߴ��� ������ prob�� �浹�˻簡 ����ȴ�..
	CollisionDetect();
	
	//Scene�� ���� ��ü��� ������Ʈ�� Update
	CScene::Update(deltaTime);

	
	//�浹�� ���� Update����
	//for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
	//	//(*m_it)->



	//}

}

void CGameScene::Render(const HDC& hDC)
{
	CScene::Render(hDC);
	//InvalidateRect(NULL, NULL, TRUE);
}

//Player�� Enemy
//Player�� Probs
//Enemy�� Probs
//�ϴ� �ϵ��ڵ�
//Player�� Probs�� �浹�� ��� �ٴ��̸� ��� Ƣ���,
//����� �浹�ѰŸ� ������ ���ƾ���.
//�浹���� �� �浹�� Object�� ���� ������ �Ѱ�����Ѵ�.
void CGameScene::CollisionDetect()
{
	//Player�� Background, UI�� ������ ��� Layer�� Object��� �浹 �˻�.
	for (auto it = FindLayer(TEXT("Player"))->GetObjectList().begin();
		it != FindLayer(TEXT("Player"))->GetObjectList().end(); ++it)
	{		
		for (m_it = m_LayerList.begin(); m_it != m_LayerList.end(); ++m_it) {
			if ( ((*m_it)->GetLayerTag() == TEXT("Background")) || ((*m_it)->GetLayerTag() == TEXT("Player")) )
				continue;

			for ( auto& object : ((*m_it)->GetObjectList()) ) {
				//m_pCollisionDetector->Update( static_cast<Collider*>(value->GetComponent(TEXT("Collider"))), 
				//	static_cast<Collider*>( (*it)->GetComponent(TEXT("Collider")) ) );
				m_pCollisionDetector->Update((*it), object); //it : player

			}
		}
	}


}

//�ش� Scene�� ������ �� ȣ���ϴ� �޼ҵ�.

void CGameScene::ResetScene()
{
	//ResetŰ �˻�
	if (KEY_DOWN(VK_BACK)) {

		Init();
	}
}

