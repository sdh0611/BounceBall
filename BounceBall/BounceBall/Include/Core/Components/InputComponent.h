#pragma once

#include "..\..\..\stdafx.h"
#include "ComponentBase.h"


class InputComponent :public ComponentBase {

public:
	InputComponent();
	virtual ~InputComponent() = default;

	
public:
	virtual void Init(class CObject*);
	virtual void Update();



};