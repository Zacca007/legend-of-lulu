#include "../lulu/link.hpp"
#include "../lulu/room.hpp"
namespace lulu
{
    Link::Link(pair position, pair size, pair speed, Room *room) : Actor(position, size, speed, room) {}
    Link::Link(pair position, pair size, pair speed, Room *room, const std::string &sprite) : Actor(position, size, speed, room, sprite) {}

    void Link::move()
    {
        int key = _room->getCurrentKey();
        switch (key)
        {
        case 262: // right
            _position.x += _speed.x;
            break;

        case 263: // left
            _position.x -= _speed.x;
            break;

        case 264: // down
            _position.y += _speed.y;
            break;

        case 265: // up
            _position.y -= _speed.y;
            break;

        default:
            break;
        }
    }
} // namespace lulu