#pragma once
#include "WinBase.h"

class WindowMain:public WinBase
{
public:
	WindowMain();
	~WindowMain();
protected:
	void paint(SkCanvas* canvas) override;
private:
	void initPosSize();

};