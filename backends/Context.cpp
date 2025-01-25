#include "Context.h"
#include "OpenGL.h"

Context::Context(WinBase* win) :win{win}
{
}

Context::~Context()
{
}

std::unique_ptr<Context> Context::create(WinBase* win)
{
	return std::make_unique<OpenGL>(win);
}
