#include "../lulu/link.hpp"
#include "../lulu/room.hpp"
#include "../lulu/types.hpp"

namespace lulu
{
    Link::Link(pair position, pair size, pair speed, Room *room)
        : Actor(position, size, speed, room) {}

    Link::Link(pair position, pair size, pair speed, Room *room, const std::string &sprite)
        : Actor(position, size, speed, room, sprite) {}

    void Link::move()
    {
        const std::vector<Key> &keys = _room->currentKeys();
        const pair &roomPos = _room->position();
        const pair &roomSize = _room->size();

        for (int key : keys)
        {
            switch (key)
            {
            case right:
                if (_position.x + _size.x + _speed.x <= roomPos.x + roomSize.x)
                    _position.x += _speed.x;
                else
                    _position.x = roomPos.x + roomSize.x - _size.x;
                break;

            case left:
                if (_position.x - _speed.x >= roomPos.x)
                    _position.x -= _speed.x;
                else
                    _position.x = roomPos.x;
                break;

            case down:
                if (_position.y + _size.y + _speed.y <= roomPos.y + roomSize.y)
                    _position.y += _speed.y;
                else
                    _position.y = roomPos.y + roomSize.y - _size.y;
                break;

            case up:
                if (_position.y - _speed.y >= roomPos.y)
                    _position.y -= _speed.y;
                else
                    _position.y = roomPos.y;
                break;

            default:
                break;
            }
        }
    }
}