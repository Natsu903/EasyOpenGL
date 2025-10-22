#include <Windows.h>
#include <iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")

void render() {
    sgl.clear();

    for (uint32_t i = 0; i < app->getWidth(); ++i)
    {
        //sgl.drawPoint(i, 500, RGBA(255, 255, 255));
        for (uint32_t j = 0; j < app->getHeight(); ++j)
        {
            uint32_t v=std::rand() % 255;
            RGBA color = RGBA(v, v, v, v);
            sgl.drawPoint(i, j, color);
        }
    }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    if (!app->initApplication(hInstance, 800, 600)) {
        return -1;
    }
    
    sgl.initSurface(app->getWidth(), app->getHeight(),app->getCanvasBuffer());

    bool alive = true;
    while (alive) {
        alive = app->peekMessage();
        render();
        app->show();
    }
    
    return 0;
}