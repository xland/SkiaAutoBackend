#include "WinBase.h"
//#include "gl/WindowContext.h"
//#include "gl/WindowContextFactory_win.h"

//std::unique_ptr<skwindow::WindowContext> fWindowContext;
WinBase::WinBase()
{
}

WinBase::~WinBase()
{
}
void WinBase::show()
{
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}
void WinBase::createWindow()
{
    const TCHAR clsName[] = L"SkiaApp";
    static WNDCLASSEX wcex;
    static bool isClsReg = false;
    auto hinstance = GetModuleHandle(NULL);
    if (!isClsReg) {
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
        wcex.lpfnWndProc = &WinBase::wndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hinstance;
        wcex.hIcon = LoadIcon(hinstance, IDI_APPLICATION);
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = nullptr;
        wcex.lpszClassName = clsName;
        wcex.hIconSm = LoadIcon(hinstance, IDI_APPLICATION);
        if (!RegisterClassEx(&wcex)) {
            return;
        }
        isClsReg = true;
    }
    hwnd = CreateWindowEx(NULL, clsName, clsName, WS_OVERLAPPEDWINDOW,
        x, y, w, h, nullptr, nullptr, hinstance, nullptr);
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);
    //fWindowContext = skwindow::MakeGLForWin(hwnd);
    ctx = Context::create(this);
}

LRESULT WinBase::wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    auto win = (WinBase*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
    switch (msg)
    {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        BeginPaint(hWnd, &ps);

        //auto surface = fWindowContext->getBackbufferSurface();
        auto surface = win->ctx->getSurface();
        SkRect rect = SkRect::MakeXYWH(win->w - 200, win->h - 200, 180, 180);
        auto canvas = surface->getCanvas();
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setColor(0xff00ffff);
        canvas->drawOval(rect, paint);
        //if (auto dContext = fWindowContext->directContext()) {
        //    dContext->flushAndSubmit(surface.get());
        //}
        //fWindowContext->swapBuffers();
        win->ctx->paint();

        EndPaint(hWnd, &ps);
        return 0;
    }
    case WM_ACTIVATE: {
        // disable/enable rendering here, depending on wParam != WA_INACTIVE
        break;
    }
    case WM_SIZE: {
        win->w = LOWORD(lParam);
        win->h = HIWORD(lParam);
        //fWindowContext->resize(win->w, win->h);
        win->ctx->resize();
        return 0;
    }
    case WM_DESTROY:
    {
        SetWindowLongPtr(hWnd, GWLP_USERDATA, 0);
        return 0;
    }
    default: {
        break;
    }
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}