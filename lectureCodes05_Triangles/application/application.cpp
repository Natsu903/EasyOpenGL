#include "application.h"
#include <iostream>

Application* Application::mInstance = nullptr;
Application* Application::getInstance() {
    if (!mInstance) {
        mInstance = new Application();
    }
    return mInstance;
}

Application::Application() {}
Application::~Application() {}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    app->handleMessage(hWnd, msg, wParam, lParam);
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool Application::initApplication(HINSTANCE hInstance, const uint32_t& width, const uint32_t& height) 
{ 
    mWidth=width;
    mHeight=height;
    registerWindowClass(hInstance);

    if(!createWindow(hInstance))
    {
        return false;
    }

    mHdc=GetDC(mHwnd);
    mCanvasDc=CreateCompatibleDC(mHdc);

    BITMAPINFO bmpInfo{};
    bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmpInfo.bmiHeader.biWidth = mWidth;
    bmpInfo.bmiHeader.biHeight = mHeight;
    bmpInfo.bmiHeader.biPlanes = 1;
    bmpInfo.bmiHeader.biBitCount = 32;
    bmpInfo.bmiHeader.biCompression = BI_RGB;

    mhBmp=CreateDIBSection(mCanvasDc, &bmpInfo, DIB_RGB_COLORS, &mCanvasBuffer, NULL, 0);

    SelectObject(mCanvasDc, mhBmp);
    memset(mCanvasBuffer, 0, mWidth * mHeight * 4);

    return true;
}

ATOM Application::registerWindowClass(HINSTANCE hInstance) 
{
    WNDCLASSEXW wndClass;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WindowProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = mWindowClassName;
    wndClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
    return RegisterClassExW(&wndClass);
}

BOOL Application::createWindow(HINSTANCE hInstance) 
{ 
    mWindowInst = hInstance;
    auto dwExstyle = WS_EX_APPWINDOW ;
    auto dwStyle = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    RECT windowRect;
    windowRect.left = 0L;
    windowRect.top = 0L;
    windowRect.right = (long)mWidth;
    windowRect.bottom = (long)mHeight;
    AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExstyle);

    mHwnd=CreateWindowW(
        mWindowClassName,
        (LPCWSTR)"GraphicLearning",
        dwStyle ,
        500,
        500,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        nullptr,
        nullptr,
        hInstance,
        nullptr);

        if(!mHwnd) {
            std::cout<<"CreateWindowW failed!"<<std::endl;
            return FALSE;
        }

        ShowWindow(mHwnd, true);
        UpdateWindow(mHwnd);

        return TRUE;
}

bool Application::peekMessage() 
{ 
    MSG msg;
    if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return mAlive;
}

void Application::show()
{
    BitBlt(mHdc, 0, 0, mWidth, mHeight, mCanvasDc, 0, 0, SRCCOPY);
}

void Application::handleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) 
    {
    case WM_CLOSE:
    {
        DestroyWindow(hWnd);
        break;
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        mAlive = false;
        break;
    }
    }
}
