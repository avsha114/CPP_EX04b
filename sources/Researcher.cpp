#include "Researcher.hpp"

using namespace std;

namespace pandemic
{
    Player& Researcher::discover_cure(Color color)
    {
        //Check if the cure was already found:
        if (board.curesList().contains(color))
        {
            return *this;
        }

        //Check if we have enough cards from the desired color:
        const int cardsNeeded = 5;
        int checkForCards = cardsNeeded;
        for (City city : cards)
        {
            if (colorByCity.at(city) == color)
            {
                checkForCards--;
            }
        }

        //If we don't have enough cards:
        if (checkForCards > 0)
        {
            throw invalid_argument("Illegal action: Not enough cards from the desired color!");
        }

        //Now we can go through our cards and throw the cards in the desired color:
        set<City>::iterator iter = cards.begin();
        checkForCards = cardsNeeded;
        while (iter != cards.end())
        {
            if (colorByCity.at(*iter) == color)
            {
                iter = cards.erase(iter);
                checkForCards--;
            }
            else
            {
                iter++;
            }
            if (checkForCards == 0)
            {
                break;
            }
        }
        
        board.curesList().insert(color); //Change the cure value to true for the desired color
        return *this;
    }
}