#pragma once
#include "WinBase.h"

class WindowMain:public WinBase
{
public:
	WindowMain();
	~WindowMain();
private:
	void initPosSize();

};