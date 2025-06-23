#include "room.hpp"
#include "actor.hpp"
#include <algorithm>

namespace lulu
{
    Room::Room(const std::string &sprite)
        : _sprite(sprite), _position({0.0f, 0.0f})
    {
    }

    Room::Room(const std::string &sprite, const pair &position)
        : _sprite(sprite), _position(position)
    {
    }

    Room::~Room()
    {
        // Non eliminiamo gli attori, solo li rimuoviamo dal vettore
        _actors.clear();
    }

    void Room::add(Actor *actor)
    {
        if (actor != nullptr)
        {
            // Verifica che l'attore non sia già presente
            auto it = std::find(_actors.begin(), _actors.end(), actor);
            if (it == _actors.end())
            {
                _actors.push_back(actor);
            }
        }
    }

    void Room::kill(Actor *actor)
    {
        auto it = std::find(_actors.begin(), _actors.end(), actor);
        if (it != _actors.end())
        {
            _actors.erase(it);
        }
    }

    Room &Room::operator+=(Actor &actor)
    {
        add(&actor);
        return *this;
    }

    Room &Room::operator+=(Actor *actor)
    {
        add(actor);
        return *this;
    }
}