#pragma once

#include "CObject.h"
#include "..\..\..\stdafx.h"


class CProbs :public CObject {
public:
	CProbs(UINT width, UINT height);
	CProbs(float left, float top, float right, float bottom);
	virtual ~CProbs();


public:
	virtual bool Init() override;
	virtual void Update(const double& deltaTime) override;
	virtual void Render(const HDC& hDC) override;


public:
	UINT GetProbsWidth() const { return m_iWidth; }
	void SetProbsWidth(UINT width) { if(width > 0) m_iWidth = width; }
	UINT GetProbsHeight() const { return m_iHeight; }
	void SetProbsHeight(UINT height) { if(height > 0) m_iHeight = height; }
	//void SetProbsSize(UINT width, UINT height){ }


private:



private:
	UINT			m_iWidth;
	UINT			m_iHeight;
	Types::Rect	m_ProbSize;


};