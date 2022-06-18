#include <iostream>
using namespace std;
#include <vector>
const int Games_10 = 10;
// #include "Team.hpp"
#include "Game.hpp"
class Schedule{
    private:
        vector<Team*>_S_League;
        vector<std::pair<Team*,Team*>> games;
    public:
        Schedule(vector<Team*>&S_League);
        void GeneratorGames();
};