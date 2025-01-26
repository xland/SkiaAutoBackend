

#include "WindowMain.h"

WindowMain::WindowMain()
{
    initPosSize();
    createWindow();
}

WindowMain::~WindowMain()
{
}

void WindowMain::paint(SkCanvas* canvas)
{
    sk_sp<SkData> data{ SkData::MakeFromFileName("D:\\project\\SkiaAutoBackend\\avatar.png")};
    sk_sp<SkImage> img = SkImages::DeferredFromEncodedData(data);
    ctx->textureFromImage(img);
    //SkImages::TextureFromImage()
    //auto gpuImage = img->makeTextureImage(context.get());
    canvas->drawImage(img, 0, 0);
    SkRect rect = SkRect::MakeXYWH(w - 200, h - 200, 180, 180);
    SkPaint paint;
    paint.setAntiAlias(true);
    if (ctx->backendType == "OpenGL") {
        paint.setColor(0xffffff00);
        canvas->drawOval(rect, paint);
    }
    else {
        paint.setColor(0xff00ffff);
        canvas->drawRect(rect, paint);
    }    
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


