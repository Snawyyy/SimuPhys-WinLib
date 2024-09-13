#pragma once
#include "Physics.h"
#include <windows.h>
#include "WindowManager.h"

struct Vector2
{
    float x;
    float y;
};

struct physicsObj
{
    Vector2 pos;
    float mass = 1;
    Vector2 velocity = {0 ,0};
    float radius;
    float restitution = 0.9; // Restitution coefficient (0 to 1, where 1 is perfectly elastic)
};

class RigidBody : public Physics
{
private:
    bool isDragging = false;
    POINT clickOffset;

    // Previous body x,y coords
    float preBodyX;
    float preBodyY;

    float gravity = 9.8; // Gravity (vertical acceleration)
    float friction = 0.4f;
    float staticFriction = 0.5f;
    float dampingFactor = 0.9f; // damping factor for energy loss on bounce
    const double G = 6.67430e-11;  // gravitational constant in m^3 kg^-1 s^-2
    const double EARTH_MASS = 5.9722e24;  // mass of the Earth in kg
    const double EARTH_RADIUS = 6.371e6;  // radius of the Earth in meters

    void CalculateTime();
    void UpdatePosition();
    void ApplyWorldGravity();
    void ApplyFriction();
    void BorderCollisions();
    void Draggable();
    int GetTaskbarHeight();

public:
    physicsObj body;

    Vector2 force = { 0.0f, 0.0f };
    bool worldGravity = true;

    RigidBody(HWND windowHandle);
    void RunPhysics() override;
    void ApplyForce(float addForceX, float addForceY);
    void ApplyGravity(physicsObj other);
    void Grab();
    void TrackGrabbing();
    void Ungrab();    
    void CalculateCollisions(physicsObj& other);
    void CalculateCollisionsWithWindow(const WindowInfo& window);

    float Clamp(float num, float min, float max);

};
