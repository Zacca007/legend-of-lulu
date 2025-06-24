#include <raylib.h>
#include "lulu/lulu..hpp"
#include <vector>
#include <array>

std::vector<lulu::Key> getCurrentKeys()
{
    std::vector<lulu::Key> active_keys;
    static const std::array<lulu::Key, 4> keys_to_check = {lulu::down, lulu::up, lulu::left, lulu::right}; // arrow keys

    for (lulu::Key key : keys_to_check)
    {
        if (IsKeyDown(key))
        {
            active_keys.push_back(key);
        }
    }
    return active_keys;
}

int main()
{
    const lulu::pair screenSize{800, 550}, roomSize{600, 350}, roomPos{100, 100};
    lulu::Room room(roomPos, roomSize);
    lulu::Link link({roomSize.x / 2, roomSize.y / 2}, {50, 50}, {15, 15}, &room);
    std::vector<lulu::Key> active_keys;

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

        active_keys = getCurrentKeys();
        room.tick(active_keys);
        EndDrawing();
    }

    UnloadTexture(bg);
    CloseWindow();

    return 0;
}
