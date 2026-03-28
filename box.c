#include "box.h"
#include <stdbool.h>
#include <math.h>

Box create_box(float x, float y, float side, float mass, float velx) {
    Box box;
    box.x = x;
    box.y = y;
    box.side = side;
    box.mass = mass;
    box.velx = velx;
    return box;
}
int UpdateBox(Box* box, int screen_width) {
    box->x += box->velx;
    if(box->x + box->side > screen_width){
        box->x = screen_width - box->side;
        box->velx = -box->velx;
        return 1;
    }
    return 0;
}
bool DetectCollision(Box* box1, Box* box2) {
    float left1 = box1->x;
    float right1 = box1->x + box1->side;
    float left2 = box2->x;
    float right2 = box2->x + box2->side;
    return !(right1 < left2 || right2 < left1);
}
void HandleCollision(Box* box1, Box* box2){
    float m1 = box1->mass;
    float m2 = box2->mass;
    float u1 = box1->velx;
    float u2 = box2->velx;
    float v1 = ((m1 - m2)/(m1 + m2)) * u1 + ((2 * m2)/(m1 + m2)) * u2;
    float v2 = ((m2 - m1)/(m1 + m2)) * u2 + ((2 * m1)/(m1 + m2)) * u1;
    box1->velx = v1;
    box2->velx = v2;
}