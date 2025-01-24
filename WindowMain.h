#pragma once
#include "WinBase.h"


//#include <gl/DisplayParams.h>
//#include <gl/SkWGL.h>
//#include <gl/WindowContext.h>
//#include <gl/GLWindowContext.h>
//#include <gl/GLTestContext.h>
//#include <gl/WindowContextFactory_win.h>

class WindowMain:public WinBase
{
public:
	WindowMain();
	~WindowMain();
private:
	void initPosSize();

};