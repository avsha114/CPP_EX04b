#include <map>
#include <set>
#include <iostream>
#include "Board.hpp"

using namespace std;

namespace pandemic
{
    int & Board::operator[](City city)
    {
        return diseaseLevels[city];
    }

    bool Board::is_clean()
    {
        for (auto const& [key,value] : diseaseLevels)
        {
            if (value != 0) {return false;}
        }
        return true;
    }

    std::ostream& operator<<(std::ostream& out, Board& b)
    {
        for (auto const &c :b.curesFound)
        {
            out << c <<endl;
        }
        return out;
    }
}