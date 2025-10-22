#include <Windows.h>
#include <iostream>
#include "application/application.h"

#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    if (!app->initApplication(hInstance, 800, 600)) {
        return -1;
    }
    
    bool alive = true;
    while (alive) {
        alive = app->peekMessage();
    }
    
    return 0;
}