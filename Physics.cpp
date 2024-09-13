#include "Physics.h"

int Physics::GetTaskbarHeight()
{
    APPBARDATA abd;
    memset(&abd, 0, sizeof(abd));
    abd.cbSize = sizeof(abd);

    if (SHAppBarMessage(ABM_GETTASKBARPOS, &abd))
    {
        return abd.rc.bottom - abd.rc.top;
    }
    else
    {
        // If the function fails, return a default value (e.g., 0)
        return 0;
    }
}

void Physics::UpdateSize()
{
}

Physics::Physics(HWND windowHandle)
{
    hWnd = windowHandle;
    UpdateSize();
}

HWND Physics::GetWindowHandle()
{
    return this->hWnd;
}

void Physics::SetWindowHandle(HWND handle)
{
    this->hWnd = handle;
    UpdateSize();
}

void Physics::RunPhysics()
{
}
