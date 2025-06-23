#include "actor.hpp"
#include "room.hpp" // Ora possiamo includere room.hpp senza problemi

namespace lulu
{
    Actor::Actor(pair position, pair size, pair speed, Room *room)
        : _position(position), _size(size), _speed(speed), _sprite(""), _room(room)
    {
    }

    Actor::Actor(pair position, pair size, pair speed, Room *room, const std::string &sprite)
        : _position(position), _size(size), _speed(speed), _sprite(sprite), _room(room)
    {
    }

    void Actor::addToRoom()
    {
        if (_room != nullptr)
        {
            *_room += this; // Ora questo funziona!
        }
    }

    void Actor::setPosition(const pair &pos)
    {
        _position = pos;
    }

    void Actor::setSpeed(const pair &speed)
    {
        _speed = speed;
    }
}