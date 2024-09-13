#pragma once
#include "RigidBody.h"
#include "WindowIdManager.h"
#include "MemoryManager.h"
#include "WindowManager.h"

class WindowPhysics : public RigidBody
{
public:
    int id;

    WindowPhysics(HWND WindowHandle);

    void SetTimerID(UINT id);
    UINT GetTimerID() const;

    void UpdateSize() override;
    void RunPhysics() override;
    int GetId();


private:
    UINT timerID;

    void ApplyCollisions();
    bool isColliding(const physicsObj& other);
    bool isCollidingWithWindow(const WindowInfo& window);
};
