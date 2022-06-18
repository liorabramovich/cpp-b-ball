#include "sources/League.hpp"
// #include "sources/Game.hpp"
// #include "sources/Team.hpp"
#include "doctest.h"
using namespace std;


TEST_CASE("BUGS , ERRORS"){
    string team_name = "Team1";
    Team *team1 = new Team(team_name,0.2);
    CHECK_THROWS(Game *G = new Game(team1 , team1));
    delete team1;
    League L{};
    CHECK_THROWS(L.Add(team1));
    CHECK_THROWS(Team *Over1Talent = new Team(team_name , 5));
    CHECK_THROWS(Team *Under0Talent = new Team(team_name , -3));
}

TEST_CASE("Random League"){
    std::vector<Team*> teams;
    string Team_Name = "TeamNum1";
    Team *TeamNum1 = new Team(Team_Name , 0.4);
    teams.push_back(TeamNum1);
    League L{teams};
    L.Play();
    CHECK_EQ(L.get_T().size() , 20);
    League L2{};
    L2.Play();
    CHECK_EQ(L2.get_T().size() , 20);
}

TEST_CASE("Game"){
    string name  = "T1";
    string name2  = "T2";
    Team T1{name , 0.5};
    Team T2{name2 , 0.6};
    for(unsigned int i = 0 ; i < 2000 ; i++){
    Game g{&T1 , &T2};

    CHECK(g.get_res().first > 55);
    CHECK(g.get_res().first <= 100);
    CHECK(g.get_res().second > 50);
    CHECK(g.get_res().second <= 100);

    }
}

TEST_CASE("Functions"){
    string name = "T1";
    string name2 = "T2";
    string name3 = "T3";
    Team T1{name , 0.8};
    CHECK_NOTHROW(T1.update_good_points(56));
    CHECK_EQ(T1.get_good_points() , 56);
    T1.update_win_streak();
    CHECK_EQ(T1.get_win_streak() , 1);
    CHECK_EQ(T1.getMaxTeamStreak('L') , 1);
    CHECK(T1.get_L()==0);
    League L{};
    L.Play();
    for(unsigned int i = 0 ; i < L.get_T().size();i++){
        CHECK(L.get_T()[i]->get_good_points()>0);
        CHECK(L.get_T()[i]->get_bad_points()>0);
    }
    Team T2 {name2 , 0.81};
    Team T3 {name3 , 0.85};
    Game g{&T2 , &T3};
        unsigned int Home =  g.get_res().first;
        unsigned int Out= g.get_res().second;
        CHECK(T2.get_good_points()==Home);
        CHECK(T2.get_bad_points()==Out);
        CHECK(T2.remainder()==(int)Home-(int)Out);
        CHECK(T3.get_good_points()==Out);
        CHECK(T3.get_bad_points()==Home);
        CHECK(T3.remainder()==(int)Out-(int)Home);
    if(g.get_res().first>g.get_res().second){
        CHECK(T2.get_win_streak()==1);
        CHECK(T2.get_W()==1);
        CHECK(T3.get_loss_streak()==1);
        CHECK(T3.get_L()==1);
    }else{
        CHECK(T3.get_win_streak()==1);
        CHECK(T3.get_W()==1);
        CHECK(T2.get_loss_streak()==1);
        CHECK(T2.get_L()==1);
    }

}
