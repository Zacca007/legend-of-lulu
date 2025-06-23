#pragma once
#include "actor.hpp"
#include <vector>
#include <string>
namespace lulu
{
    class Link : public Actor
    {
    private:
        animations animations_up;
        animations animations_down;
        animations animations_left;
        animations animations_right;

    public:
        Link(pair position, pair size, pair speed, Room *room);
        Link(pair position, pair size, pair speed, Room *room, const std::string &sprite);

        // metodi
        void move() override;
    };
} // namespace lulu
