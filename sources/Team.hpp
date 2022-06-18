#include <iostream>
using namespace std;
#include <utility>
#include <bits/stdc++.h>

const int scored_80 = 80;
class Team{
    private:
        string _name;
        double _t;
        string _team_streak;
        unsigned int _good_points;
        unsigned int _bad_points;
        unsigned int Over_80;
        std::pair<unsigned int,unsigned int> _teamscoreboard;
        


    public:


    Team(string &name , double t);
    double get_t()const;
    string get_Team_name();
    unsigned int get_W()const;
    unsigned int get_L()const;
    unsigned int get_win_streak();
    unsigned int get_loss_streak();
    unsigned int get_good_points()const;
    unsigned int get_bad_points()const;
    unsigned int getMaxTeamStreak(char X);
    unsigned int get_Over_80()const;
    void update_W();
    void update_L();
    void update_win_streak();
    void update_loss_streak();
    void update_good_points(unsigned int x);
    void update_bad_points(unsigned int x);
    int remainder()const;
    void print();


};