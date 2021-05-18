#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Player &Medic::treat(City city)
    {
        //Check if there's a disease to cure:
        if (board[city] == 0)
        {
            throw invalid_argument("Illegal action: No disease cubes to treat!");
        }
        //Check if we are in the desired city:
        if (location != city)
        {
            throw invalid_argument("Illegal action: You are not in the city!");
        }
        //Cure the city:
        board[city] = 0;

        return *this;
    }

    void Medic::autoCure()
    {
        if (board.curesList().contains(colorByCity.at(location)))
        {
            board[location] = 0;
        }
    }
}