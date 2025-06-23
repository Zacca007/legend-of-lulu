#include "../lulu/room.hpp"
#include "../lulu/actor.hpp"
#include <algorithm>

namespace lulu
{
    Room::Room(pair position, pair size) : _position(position), _size(size) {}

    Room::~Room()
    {
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

    void Room::_captureKey(int key)
    {
        _current_key = key;
    }

    void Room::tick(int key)
    {
        _captureKey(key);
        for (Actor *actor : _actors)
        {
            actor->move();
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