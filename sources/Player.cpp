#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace pandemic
{
    Player &Player::drive(City city)
    {   
        //Check if the move is legal:
        if (city == location)
        {
            throw invalid_argument("Illegal action: You can't drive to your current location!");
        }
        if (!connectedCities.at(location).contains(city))
        {
            throw invalid_argument{"Illegal action: Cities are not connected!"};
        }
        //Now we can drive to the city:
        location = city;
        autoCure(); //For the Medic role
        return *this;
    }

    Player &Player::fly_direct(City city)
    {
        //Check if the move is legal:
        if (city == location)
        {
            throw invalid_argument("Illegal action: You can't fly to your current location!");
        }

        if (!cards.contains(city))
        {
            throw invalid_argument("Illegal action: You must have the city card to fly directly!");
        }
        //Now we can fly to the city:
        cards.erase(city);
        location = city;
        autoCure(); //For the Medic role
        return *this;
    }

    Player &Player::fly_charter(City city)
    {
        //Check if the move is legal:
        if (city == location)
        {
            throw invalid_argument("Illegal action: You can't drive to your current location!");
        }
        if (!cards.contains(location))
        {
            throw invalid_argument("Illegal action: You must have current location's card to fly charter!");
        }
        //Now we can fly to the city:
        cards.erase(location);
        location = city;
        autoCure(); //For the Medic role
        return *this;
    }

    Player &Player::fly_shuttle(City city)
    {
        //Check if the move is legal:
        if (city == location)
        {
            throw invalid_argument("Illegal action: You can't drive to your current location!");
        }
        set<City> &rsList = board.rsList();
        if (!rsList.contains(location) || !rsList.contains(city))
        {
            throw invalid_argument("Illegal action: Cities must have research centers to fly shuttle!");
        }
        location = city;
        autoCure();
        return *this;
    }

    Player &Player::build()
    {
        set<City> &rsList = board.rsList();

        //Check if the player has the current location's card && the location has no RS
        if (cards.contains(location) && !rsList.contains(location))
        {
            rsList.insert(location);
            cards.erase(location);
        }
        //If it has no RS - it means that he doesn't have the location's card
        else if (!rsList.contains(location))
        {
            throw invalid_argument("Illegal action: You must have the location's card to build a research station!");
        }

        return *this;
    }

    Player &Player::discover_cure(Color color)
    {
        //Check if we have a research station or a cure:
        if (!board.rsList().contains(location))
        {
            throw invalid_argument("Illegal action: Current city must have a research station to discover a cure!");
        }
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
        while (iter != cards.end() && checkForCards > 0)
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
        }

        board.curesList().insert(color); //Change the cure value to true for the desired color
        return *this;
    }

    Player &Player::treat(City city)
    {
        //Check if there's a disease to cure:
        if (board[city] == 0)
        {
            throw invalid_argument("Illegal action: No disease cubes to treat!");
        }
        //Check if we are in the desired city:
        if (location != city)
        {
            throw invalid_argument("Illegal action: You arenot in the city!");
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

    Player &Player::take_card(City city)
    {
        cards.insert(city);
        return *this;
    }
}