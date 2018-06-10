//Probs 객체 정의하고 Collision 테스팅해볼 것.(05.30)

#include "..\..\..\stdafx.h"
#include "..\..\..\Include\Scene\Object\CProbs.h"
#include "..\..\..\Include\Core\Components\ColliderBox.h"



//ProbSize부분은 아직 Offset을 적용하지 않은 상태에서 초기화함.
//추후 Offset을 적용하게 되면 다시 수정할 것.(5.31)
CProbs::CProbs(UINT width, UINT height) :
	CObject(Types::OT_PROBS, Types::Point(0, 300)),
	m_iWidth(width), m_iHeight(height),
	m_ProbSize(Types::Rect(m_fObjectPoint.x, m_fObjectPoint.y,
		m_fObjectPoint.x+(float)m_iWidth, m_fObjectPoint.y+(float)m_iHeight))
{

}


CProbs::CProbs(float left, float top, float right, float bottom) :
	CObject(Types::OT_PROBS, Types::Point(left, top)),
	m_iWidth(right - left), m_iHeight(bottom - top), 
	m_ProbSize( {left, top, right, bottom} )
{
	//Debug::MessageInfo(TEXT("Probs init"));

}

CProbs::~CProbs()
{

}

bool CProbs::Init()
{
	//컴포넌트들 추가
	//Debug::MessageInfo(TEXT("Add Box!"));
	AddComponent( TEXT("Collider"), new ColliderBox( (this), m_ProbSize ) );
	//TCHAR buf[1024];
	//wsprintf(buf, TEXT("width : %d, height : %d"), m_iWidth, m_iHeight);
	//Debug::MessageInfo(buf);

	//컴포넌트들 초기화
	CObject::Init();

	return true;
}

void CProbs::Update(const double & deltaTime)
{

	CObject::Update(deltaTime);

}

void CProbs::Render(const HDC & hDC)
{

	Rectangle(hDC, m_ProbSize.left, m_ProbSize.top, 
		m_ProbSize.right, m_ProbSize.bottom);

	TCHAR temp[1024];
	ColliderBox* box = static_cast<ColliderBox*>(GetComponent(TEXT("Collider")));
	Types::Rect rect = box->GetBoxSize();

	Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);

	wsprintf(temp, TEXT("Box : (%3ld, %3ld, %3ld, %3ld)"), (LONG)rect.left, (LONG)rect.top, (LONG)rect.right, (LONG)rect.bottom);
	TextOut(hDC, 0, 60, temp, lstrlen(temp));

}
