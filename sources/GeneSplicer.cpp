#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    Player &GeneSplicer::discover_cure(Color color)
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
        

        //Check if we have enough cards:
        const int cardsNeeded = 5;
        int checkForCards = cardsNeeded;
    
        //If we don't have enough cards:
        if (cards.size() < checkForCards)
        {
            throw invalid_argument("Illegal action: Not enough cards!");
        }

        //Now we can go through our cards and throw 5 cards:
        set<City>::iterator iter = cards.begin();
        while (iter != cards.end())
        {
            iter = cards.erase(iter);
            checkForCards--;
            if (checkForCards == 0)
            {
                break;
            }
        }

        board.curesList().insert(color); //Change the cure value to true for the desired color
        return *this;
    }
}