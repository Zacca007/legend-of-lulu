#include "../lulu/actor.hpp"
#include "../lulu/room.hpp"

namespace lulu
{
    Actor::Actor(pair position, pair size, pair speed, Room *room)
        : _position(position), _size(size), _speed(speed), _room(room)
    {
        if (_room)
        {
            *_room += this;
        }
    }

    Actor::Actor(pair position, pair size, pair speed, Room *room, const std::string &sprite)
        : Actor(position, size, speed, room)
    {
        _sprite = sprite;
    }

    void Actor::setPosition(const pair &pos)
    {
        _position = pos;
    }

    void Actor::setSpeed(const pair &speed)
    {
        _speed = speed;
    }

    void Actor::move() {}
}