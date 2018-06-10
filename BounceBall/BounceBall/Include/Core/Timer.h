#pragma once

#include "../../stdafx.h"

class Timer {
public:
	Timer() = default;
	~Timer() = default;


public:
	bool Init();
	void Update();


public:
	float GetDeltaTime() const { return m_fDeltaTime; }
	float GetFPS()	const { return m_fFPS; }


private:
	LARGE_INTEGER m_tSecond;
	LARGE_INTEGER m_tTime;
	float				m_fDeltaTime;
	float				m_fFPS;
	float				m_fFPSTime;
	float				m_iFrameMax;
	float				m_iFrame;



};