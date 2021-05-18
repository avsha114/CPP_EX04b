#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Player &Dispatcher::fly_direct(City city)
    {
        //Check if the move is legal:
        if (city == location)
        {
            throw invalid_argument("Illegal action: You can't drive to your current location!");
        }
        //If the city has a research station - no need to throw a card:
        if (board.rsList().contains(location))
        {
            location = city;
            return *this;
        }
        //If we have the city card in our hand:
        if (cards.contains(city))
        {
            cards.erase(city);
            location = city;
            return *this;
        }
        //Else:
        throw invalid_argument("Illegal action: You need to have a reseach station to fly direct with Dispatcher!");
    }

}