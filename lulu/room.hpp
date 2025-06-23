#pragma once
#include "types.hpp"
#include <string>
#include <vector>
#include <map>

namespace lulu
{
    // Forward declaration
    class Actor;

    using collisions = std::map<Actor *, std::vector<Actor *>>;

    class Room
    {
    private:
        pair _position;
        std::string _sprite;
        std::vector<Actor *> _actors;
        collisions _collisions;

    public:
        // Costruttori
        Room(const std::string &sprite);
        Room(const std::string &sprite, const pair &position);
        ~Room();

        // Getter inline
        const std::string &sprite() const { return _sprite; }
        pair position() const { return _position; }
        const std::vector<Actor *> &actors() const { return _actors; }

        // Metodi che verranno implementati nel .cpp
        void add(Actor *actor);
        void kill(Actor *actor);

        // Operatori
        Room &operator+=(Actor &actor);
        Room &operator+=(Actor *actor);
    };
}