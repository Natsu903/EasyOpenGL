#include <Windows.h>
#include <iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")

void render() {
    sgl.clear();

    Point p1{ 0, 100 };
    Point p2{ 500, 100 };
    Point p3{ 250, 500 };

    sgl.drawTriangle(p1, p2, p3);
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
