#include "FieldDoctor.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    Player& FieldDoctor::treat(City city)
    {
        //Check if there's a disease to cure:
        if (board[city] == 0)
        {
            throw invalid_argument("Illegal action: No disease cubes to treat!");
        }
        //Check if we are in or near the desired city:
        if (location != city && !connectedCities.at(location).contains(city))
        {
            throw invalid_argument("Illegal action: You are not in or near this location!");
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