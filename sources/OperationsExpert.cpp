#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic
{
    Player& OperationsExpert::build()
    {
        //If the element already exists it will do nothing.
        //Else - it will build a research station.
        board.rsList().insert(location);

        return *this;
    }
}