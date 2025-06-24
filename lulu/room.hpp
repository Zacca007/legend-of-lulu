#pragma once
#include "types.hpp"
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
        pair _size;
        std::vector<Actor *> _actors;
        collisions _collisions;
        std::vector<Key> _current_keys;
        std::vector<Key> _previous_keys;

    public:
        // Costruttori
        Room(pair position, pair size);
        ~Room();

        // Getter inline
        pair position() const { return _position; }
        pair size() const { return _size; }
        const std::vector<Actor *> &actors() const { return _actors; }
        const std::vector<Key> &currentKeys() const { return _current_keys; }

        // Metodi
        void add(Actor *actor);
        void kill(Actor *actor);
        void tick(const std::vector<Key> &keys);

        // Operatori
        Room &operator+=(Actor &actor);
        Room &operator+=(Actor *actor);
    };
}