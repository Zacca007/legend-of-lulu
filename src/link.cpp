#include "../lulu/link.hpp"
#include "../lulu/room.hpp"
#include <algorithm>
namespace lulu
{
    Link::Link(pair position, pair size, pair speed, Room *room) : Actor(position, size, speed, room) {}
    Link::Link(pair position, pair size, pair speed, Room *room, const std::string &sprite) : Actor(position, size, speed, room, sprite) {}

    void Link::move()
    {
        const std::vector<int> keys = _room->currentKeys();
        const std::vector<std::string> walls = collidingWalls();

        for (int key : keys)
        {
            switch (key)
            {
            case 262: // right
                if (std::find(walls.begin(), walls.end(), "right") == walls.end())
                    _position.x += _speed.x;
                break;

            case 263: // left
                if (std::find(walls.begin(), walls.end(), "left") == walls.end())
                    _position.x -= _speed.x;
                break;

            case 264: // down
                if (std::find(walls.begin(), walls.end(), "bottom") == walls.end())
                    _position.y += _speed.y;
                break;

            case 265: // up
                if (std::find(walls.begin(), walls.end(), "top") == walls.end())
                    _position.y -= _speed.y;
                break;

            default:
                break;
            }
        }
    }
} // namespace lulu