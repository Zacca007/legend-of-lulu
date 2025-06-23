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
        int _current_key;
        int _previous_key;

        void _captureKey(int key);

    public:
        // Costruttori
        Room(pair position, pair size);
        ~Room();

        // Getter inline
        pair position() const { return _position; }
        pair size() const { return _size; }
        const std::vector<Actor *> &actors() const { return _actors; }
        int getCurrentKey() { return _current_key; }

        // Metodi
        void add(Actor *actor);
        void kill(Actor *actor);
        void tick(int key);

        // Operatori
        Room &operator+=(Actor &actor);
        Room &operator+=(Actor *actor);
    };
}