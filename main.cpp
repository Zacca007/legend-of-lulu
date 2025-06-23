#include "raylib.h"
#include "lulu/lulu..hpp"
#include <iostream>

int main()
{
    const lulu::pair screenSize{800, 550}, roomSize{600, 350}, roomPos{100, 100};
    lulu::Room room(roomPos, roomSize);
    lulu::Link link({roomSize.x / 2, roomSize.y / 2}, {50, 50}, {10, 10}, &room);

    InitWindow(screenSize.x, screenSize.y, "Legend of Lulu - Room Test");
    Texture2D bg = LoadTexture("assets/rooms/room1.png");

    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawTexture(bg, 0, 0, WHITE);
        DrawRectangle(link.position().x, link.position().y, link.size().x, link.size().y, GRAY);

        // Debug: disegna il rettangolo della zona calpestabile
        DrawRectangleLines(room.position().x, room.position().y, room.size().x, room.size().y, YELLOW);
        int key = GetKeyPressed();
        room.tick(key);
        std::cout << key << std::endl;
        std::cout << link.position().x << std::endl;
        EndDrawing();
    }

    UnloadTexture(bg);
    CloseWindow();

    return 0;
}
