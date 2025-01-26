#pragma once

#include <windows.h>
#include <include/core/SkColorSpace.h>
#include <include/core/SkSurface.h>
#include <include/core/SkCanvas.h>
#include <include/gpu/ganesh/GrDirectContext.h>

#include "backends/Context.h"

class WinBase
{
public:
	WinBase();
	~WinBase();
	void show();
public:
	int x, y, w, h;
	HWND hwnd;
protected:
	void createWindow();
	virtual void paint(SkCanvas* canvas) = 0;
protected:
	std::unique_ptr<Context> ctx;
private:
	static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);	
};
