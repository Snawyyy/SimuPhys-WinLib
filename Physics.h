#pragma once
#include <Windows.h>
#include <cmath>
#include <algorithm>

#define SECOND_TO_MILISECOND 1000
#define VELOCITY_THRESHOLD 10

class Physics
{
private:
    int GetTaskbarHeight();

protected:
    virtual void UpdateSize();

public:
    HWND hWnd;
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int taskbarHeight = GetTaskbarHeight();
    int centerW = screenWidth / 2;
    int centerH = screenHeight / 2;

    int width;
    int height;
    float deltaTime = 0;
    DWORD lastTime;
    DWORD currentTime;

    Physics(HWND windowHandle);

    HWND GetWindowHandle();
    void SetWindowHandle(HWND handle);

    virtual void RunPhysics();
};
