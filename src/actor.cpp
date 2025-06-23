#include "../lulu/actor.hpp"
#include "../lulu/room.hpp"

namespace lulu
{
    Actor::Actor(pair position, pair size, pair speed, Room *room)
        : _position(position), _size(size), _speed(speed), _sprite(""), _room(room)
    {
        *_room += this;
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

    std::vector<std::string> Actor::collidingWalls() const
    {
        std::vector<std::string> walls;

        if (_position.x <= _room->position().x)
            walls.push_back("left");
        if (_position.y <= _room->position().y)
            walls.push_back("top");
        if (_position.x + _size.x >= _room->position().x + _room->size().x)
            walls.push_back("right");
        if (_position.y + _size.y >= _room->position().y + _room->size().y)
            walls.push_back("bottom");

        return walls; // copia (ma ottimizzata con RVO o move)
    }

    void Actor::move() {}
}