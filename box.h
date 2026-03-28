#pragma once
#include <stdbool.h>

typedef struct{
    float x;
    float y;
    float side;
    float mass;
    float velx;
} Box;

Box create_box(float x, float y, float side, float mass, float velx);
void HandleCollision(Box* box1, Box* box2);
bool DetectCollision(Box* box1, Box* box2);
int UpdateBox(Box* box, int screen_width);