#pragma once

#include "..\..\..\stdafx.h"
#include "ComponentBase.h"


class InputComponent :public ComponentBase {

public:
	InputComponent(class CObject* owner);
	virtual ~InputComponent() = default;

	
public:
	virtual void Init() override;
	virtual void Update(const double& deltaTime);


private:
	void KeyProcess();


};