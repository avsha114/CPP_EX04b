#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    Player& Scientist::discover_cure(Color color)
    {   
        //Check if the cure was already found:
        if (board.curesList().contains(color))
        {
            return *this;
        }
        //Check if we have a research station:
        if (!board.rsList().contains(location))
        {
            throw invalid_argument("Illegal action: Current city must have a research station to discover a cure!");
        }
        

        //Check if we have enough cards from the desired color:
        int testCards = cardsNeeded;
        for (City city : cards)
        {
            if (colorByCity.at(city) == color)
            {
                testCards--;
            }
        }

        //If we don't have enough cards:
        if (testCards > 0)
        {
            throw invalid_argument("Illegal action: Not enough cards from the desired color!");
        }

        //Now we can go through our cards and throw the cards in the desired color:
        testCards = cardsNeeded;
        set<City>::iterator iter = cards.begin();
        while (testCards != 0 && iter != cards.end())
        {
            if (colorByCity.at(*iter) == color)
            {
                iter = cards.erase(iter);
                testCards--;
            }
            else {iter++;}
        }

        board.curesList().insert(color); //Change the cure value to true for the desired color
        return *this;
    }
}