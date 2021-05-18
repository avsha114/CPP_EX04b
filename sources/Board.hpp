#pragma once
#include <map>
#include <set>
#include "City.hpp"

namespace pandemic
{
    class Board
    {
        std::map<City, int> diseaseLevels;
        std::set<City> researchStations;
        std::set<Color> curesFound;

    public:
        Board(){};

        int &operator[](City);
        bool is_clean();
        void remove_cures(){curesFound.clear();}
        void remove_stations(){researchStations.clear();}

        friend std::ostream &operator<<(std::ostream &, Board &);

        /*########### Private Methods ###########*/
        std::set<City> &rsList(){return researchStations;}
        std::set<Color> &curesList(){return curesFound;}
    };
}