#include "WindowMain.h"

WindowMain::WindowMain()
{
    initPosSize();
    createWindow();
}

WindowMain::~WindowMain()
{
}

void WindowMain::initPosSize()
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    w = 800;
    h = 600;
    x = (screenWidth - w) / 2;
    y = (screenHeight - h) / 2;
}


