#pragma once
#include "../global/base.h"
#include <Windows.h>

#define app Application::getInstance()

class Application {
public:
	static Application* getInstance();
    Application();
    ~Application();

    //注册窗口类，创建一个窗口并显示
    bool initApplication(HINSTANCE hInstance, const uint32_t& width=800,const uint32_t& height=600);
    void handleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    bool peekMessage();

private:
    BOOL createWindow(HINSTANCE hInstance);
    ATOM registerWindowClass(HINSTANCE hInstance);

private:
    static Application* mInstance;
    bool mAlive{true};

    HINSTANCE mWindowInst;
    WCHAR mWindowClassName[100]=L"AppWindow";
    HWND mHwnd;

    int mWidth=800;
    int mHeight=600;
};