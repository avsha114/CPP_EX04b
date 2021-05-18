#pragma once
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{
    class Scientist: public Player
    {
        int cardsNeeded;

        public:
            Scientist(Board& gameBoard, City city, int number)
                            : Player(gameBoard, city, "Scientist"), cardsNeeded(number){}
            Player& discover_cure(Color);
    };
}