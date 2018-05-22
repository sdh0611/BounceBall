#pragma once

#include "..\..\..\stdafx.h"
#include "CObject.h"


class CPlayer : public CObject{

public:
	CPlayer();
	virtual ~CPlayer();


public:
	virtual bool Init() override;
	virtual void Update() override;
	virtual void Render(const HDC& hDC) override;

	
public:


private:



private:


};