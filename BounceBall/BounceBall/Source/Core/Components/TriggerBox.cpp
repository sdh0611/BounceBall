#include "..\..\..\Include\Core\Components\TriggerBox.h"

//�̷��ϱ� ColliderType �ʱ�ȭ�� �� ��������. ColliderBox���� �պ��� �� ��.(18.07.05)
TriggerBox::TriggerBox(CObject* pOwner, float fLeft, float fTop, float fRight, float fBottom)
	:ColliderBox(pOwner, fLeft, fTop, fRight, fBottom)
{
	


}

TriggerBox::TriggerBox(CObject * pOwner, const Types::Rect & rect)
	:ColliderBox(pOwner, rect)
{


}

TriggerBox::~TriggerBox()
{


}
