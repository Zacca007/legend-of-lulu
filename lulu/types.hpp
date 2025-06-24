#pragma once
namespace lulu
{
    struct pair
    {
        float x = 0;
        float y = 0;
        // pair(float x, float y) : x(x), y(y) {}

        pair operator+(const pair &other) const
        {
            return {x + other.x, y + other.y};
        }

        pair operator-(const pair &other) const
        {
            return {x - other.x, y - other.y};
        }
    };

    enum Key
    {
        right = 262,
        left = 263,
        down = 264,
        up = 265
    };
}
