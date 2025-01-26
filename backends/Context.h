#pragma once
#include <memory>
#include <Windows.h>
#include <include/core/SkSurface.h>

class WinBase;
class Context
{
public:
	~Context();
	static std::unique_ptr<Context> create(WinBase* win);
	virtual void resize() = 0;
	virtual sk_sp<SkSurface> getSurface() = 0;
	SkCanvas* getCanvas();
	virtual void paint() = 0;
public:
protected:
	Context(WinBase* win);
protected:
	WinBase* win;
	sk_sp<SkSurface> fSurface;
private:
};

