#include <iostream>
#include "Schedule.hpp"
#include <vector>
#include <random>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


const int Teams_IN_League = 20;

class League{
    private:
        vector<Team*>_team_in_league;
        Schedule *_League_Schedule;
    public:
        League(vector<Team*>&te);
        League();
        League(const League &Other);
        League(League &&other)noexcept;
        League &operator=(const League &other);
        League& operator=(League &&) noexcept; 
        ~League();
        vector<Team*>get_T();
        void GenerateRandomTeam();
        void Play();
        void Add(Team *T);
        void get_Maximum_Win_and_Loss_Streak();
        void PositiveRemainder();
        void AvrageScore();
        void statistical_analysis(unsigned int x);
        void ScoreBoardByNumOfTeams(unsigned int x);
        void FinalScoreBoard();
        void Over_80();
        void Best_good_points();
        bool operator<(const Team &t);


};