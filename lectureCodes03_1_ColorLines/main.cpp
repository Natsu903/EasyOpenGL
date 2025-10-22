#include <Windows.h>
#include <iostream>
#include "application/application.h"
#include "gpu/gpu.h"

#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")

void render() {
    sgl.clear();

	//Point p1{ 100,100,RGBA(255,0,0,255) };
	//Point p2{ 500,600,RGBA(0,255,0,255) };

	//sgl.drawLine(p1, p2);

    int r = 150;
    Point c{ 400,300,RGBA(255,0,0,255)};

    for (float i = 0; i < 360; i += 10)
    {
        float radian=DEG2RAD(i);
        int x=r*sin(radian)+c.x;
        int y=r*cos(radian)+c.y;
        Point pt{ x,y,RGBA(rand()%255,rand()%255,rand()%255,255)};
        sgl.drawLine(c, pt);
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