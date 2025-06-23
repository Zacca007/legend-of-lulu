#pragma once
#include "types.hpp"
#include <string>
#include <vector>

namespace lulu
{
    // Forward declaration per evitare circular dependency
    class Room;

    using animations = std::vector<std::string>;

    class Actor
    {
    protected:
        pair _position;
        pair _size;
        pair _speed;
        std::string _sprite;
        Room *_room;

        std::vector<std::string> collidingWalls() const;

    public:
        // Costruttori
        Actor(pair position, pair size, pair speed, Room *room);
        Actor(pair position, pair size, pair speed, Room *room, const std::string &sprite);
        // In actor.hpp
        virtual ~Actor() = default;

        // Getter
        pair position() const { return _position; }
        pair size() const { return _size; }
        pair speed() const { return _speed; }
        const std::string &sprite() const { return _sprite; }
        Room *room() const { return _room; }

        // setter
        void setPosition(const pair &pos);
        void setSpeed(const pair &speed);

        // metodi
        virtual void move();
    };
}