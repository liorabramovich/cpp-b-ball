#include <iostream>
#include "Team.hpp"
#include <cmath>
#include <random>
const int MAX_HOME_GOOD_POINTS = 100;
const int MIN_HOME_BAD_POINTS = 55;
const int MAX_OUT_GOOD_POINTS = 100;
const int MIN_OUT_BAD_POINTS = 50;
const int Expectation = 71;
const int Variance = 5 ; 
const int Tale = 10 ;


class Game{
    private:
        Team *_In;
        Team *_Out;
        std::pair<unsigned int , unsigned int > Pair_Result; 
    public:
        Game(Team* in , Team* Out);
        void LaunchGame();
        void normal_distribution(Team *In , Team *Out);
        void GameResult(unsigned int In , unsigned int Out);
        static unsigned int Add_Bonus(Team *T ,  unsigned int &Team_Bonus);
        static void TeamWinner(Team *Winner, Team *Losser, unsigned int Win , unsigned int Loss);
        static void TeamLosser(Team *Losser , unsigned int Win ,unsigned int Loss );
        std::pair<unsigned int , unsigned int>& get_res();
        
};