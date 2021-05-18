#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <set>

namespace pandemic
{
    class Player
    {
    protected:
        std::string myRole;
        Board &board;
        City location;
        std::set<City> cards;

    public:
        Player(Board &gameBoard, City city, std::string playerRole)
            : board(gameBoard), location(city), myRole(playerRole) {}

        Player &drive(City);
        virtual void autoCure(){};
        virtual Player &fly_direct(City);
        Player &fly_charter(City);
        Player &fly_shuttle(City);
        virtual Player &build();
        virtual Player &discover_cure(Color);
        virtual Player &treat(City);
        std::string role() { return myRole; }
        Player &take_card(City);
        void remove_cards() { cards.clear(); }
    };
}