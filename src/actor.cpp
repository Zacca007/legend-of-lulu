#include "../lulu/actor.hpp"
#include "../lulu/room.hpp"

namespace lulu
{
    Actor::Actor(pair position, pair size, pair speed, Room *room)
        : _position(position), _size(size), _speed(speed), _sprite(""), _room(room)
    {
        *_room+=this;
    }

    Actor::Actor(pair position, pair size, pair speed, Room *room, const std::string &sprite)
        : _position(position), _size(size), _speed(speed), _sprite(sprite), _room(room)
    {
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