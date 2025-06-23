#pragma once
#include "types.hpp"
#include <string>

namespace lulu
{
    // Forward declaration per evitare circular dependency
    class Room;
    
    class Actor
    {
    protected:
        pair _position;
        pair _size;
        pair _speed;
        std::string _sprite;
        Room* _room;

    public:
        // Costruttori
        Actor(pair position, pair size, pair speed, Room* room);
        Actor(pair position, pair size, pair speed, Room* room, const std::string& sprite);
        
        // Getter inline (buona pratica per funzioni semplici)
        pair position() const { return _position; }
        pair size() const { return _size; }
        pair speed() const { return _speed; }
        const std::string& sprite() const { return _sprite; }
        Room* room() const { return _room; }
        
        // Metodi che verranno implementati nel .cpp
        void addToRoom();
        void setPosition(const pair& pos);
        void setSpeed(const pair& speed);
    };
}