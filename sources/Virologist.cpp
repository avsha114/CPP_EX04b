#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Player& Virologist::treat(City city)
    {
        //Check if there's a disease to cure:
        if (board[city] == 0)
        {
            throw invalid_argument("Illegal action: No disease cubes to treat!");
        }
        if (!cards.contains(city) && city != location)
        {
            throw invalid_argument("Illegal action: You need to have the city's card in your hand!");
        }
        //If there's a cure than disease level should be 0, else we should lower it by 1
        if (board.curesList().contains(colorByCity.at(city)))
        {
            board[city] = 0;
        }
        else
        {
            board[city]--;
        }
        
        return *this;
    }
}