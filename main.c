#include <raylib.h>
#include "box.h"
#include <stdbool.h>
#include <math.h>
#define digits 4

int main(void) {
    const int screen_width = 1600;
    const int screen_height = 1200;
    int collision_count = 0;
    InitWindow(screen_width, screen_height, "Box Collision Simulation");
    Box box1 = create_box(1350, 1150, 50, 1, 0);
    Box box2 = create_box(1150, 1100, 100, 100*100*100, 0.1);
    SetTargetFPS(6000);
    while (!WindowShouldClose()) {
        collision_count += UpdateBox(&box1, screen_width);
        UpdateBox(&box2, screen_width);
        if(DetectCollision(&box1, &box2)){
            collision_count++;
            HandleCollision(&box1, &box2);
        }
        BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("Box Collision Simulation", 10, 10, 20, LIGHTGRAY);
            DrawText(TextFormat("Collisions: %d", collision_count), 10, 40, 20, LIGHTGRAY);
            DrawRectangle(box1.x, box1.y, box1.side, box1.side, RED);
            DrawRectangle(box2.x, box2.y, box2.side, box2.side, BLUE);
        EndDrawing();
    }
    return 0;
}