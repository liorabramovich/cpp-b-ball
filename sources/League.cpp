#include "League.hpp"

League::League(){
    this->_League_Schedule = nullptr;
    for(unsigned int i = 0 ; i < Teams_IN_League ; i++){
        GenerateRandomTeam();
    }
}

League::League(vector<Team*>&te){
    this->_team_in_league = te;
    if(_team_in_league.size() < Teams_IN_League){
        unsigned int i = _team_in_league.size();
        while( i < Teams_IN_League){
            GenerateRandomTeam();
            i++;
        }
    }
    this->_League_Schedule = nullptr;
}

void League::GenerateRandomTeam(){
    char to_append = 'A'; 
    int j = this->get_T().size();
    std::string Team_Name = "SystemSoftware";
    
    for(unsigned int i = 0 ; i < j;i++){

        if (Team_Name == this->get_T()[i]->get_Team_name()){
            int x = (int)to_append+1;
            to_append=(char)x;
            Team_Name.push_back(to_append);

            i=0;
        }
    }
    double r = ((double) rand() / (RAND_MAX));
    Team *random = new Team(Team_Name , r);
    this->_team_in_league.push_back(random);
    
}

League::~League(){
    for(unsigned int i = 0 ; i < this->get_T().size();i++){
        delete this->get_T()[i];
    }
    delete this->_League_Schedule;
}

void League::Play(){if(this->get_T().size()<Teams_IN_League){throw std::runtime_error("Teams in league lt 20");}this->_League_Schedule=new Schedule(this->_team_in_league);this->FinalScoreBoard();}
void League::Add(Team *T){if(this->get_T().size()==Teams_IN_League){throw std::range_error("League is full");}this->_team_in_league.push_back(T);}
vector<Team*> League::get_T(){return this->_team_in_league;}
void League::get_Maximum_Win_and_Loss_Streak(){
    unsigned int i = 1;
    Team *Max_Win_Streak = this->get_T()[0];
    Team *Max_Loss_Streak = this->get_T()[0];
    while( i < this->get_T().size()){
        if(this->get_T()[i]->get_win_streak()>Max_Win_Streak->get_win_streak()){Max_Win_Streak = this->get_T()[i];};
        if(this->get_T()[i]->get_loss_streak()>Max_Win_Streak->get_loss_streak()){Max_Loss_Streak = this->get_T()[i];};
        i++;
    }
    std::cout << "Maximum win streak in league - "<< Max_Win_Streak->get_win_streak()<<std::endl;
    std::cout << "Maximum Loss streak in league - "<< Max_Loss_Streak->get_loss_streak()<<std::endl;

}


bool CompareFunction( Team *t1 ,  Team *t2){
     if(t1->get_W()>t2->get_W()){return true;}
     if(t2->get_W()>t1->get_W()){return false;}
      return t1->remainder()>t2->remainder();
     }

void League::FinalScoreBoard(){
    sort(this->_team_in_league.begin() , this->_team_in_league.end() , CompareFunction);
    for(unsigned int i = 0 ; i < this->get_T().size();i++){
        std::cout << "Rank " << i+1<< ".";
        this->get_T()[i]->print();
    }
}

void League::ScoreBoardByNumOfTeams(unsigned int x){
    for(unsigned int i =0; i < x ; i++){
        std::cout << "Rank "<<i<<". ";
        this->get_T()[i]->print();
    }
}

void League::Over_80(){
    unsigned int sum = 0;
    for(Team *t : this->get_T()){sum+=t->get_Over_80();}
    std::cout<< "in " <<  sum << " games , Was a team with more than 80 points"<<std::endl;
}

void League::Best_good_points(){
    Team *Winner = this->get_T()[0];
    for(unsigned int i = 1 ; i < this->get_T().size();i++){
        if(this->get_T()[i]->get_good_points()>Winner->get_good_points()){Winner=this->get_T()[i];}
    }
    std::cout <<"Team "<< Winner->get_Team_name()<< " scored "<< Winner->get_good_points()<< " more then any other theam in the league"<<std::endl;


}

void League::PositiveRemainder(){int res = 0;for(Team *team_to_check : this->get_T()){if(team_to_check->remainder()>0){res++;}}std::cout  <<res<<" teams have positive remainder - "<<std::endl ; }

void League::statistical_analysis(unsigned int x){
    this->get_Maximum_Win_and_Loss_Streak();
    this->PositiveRemainder();
    this->Over_80();
    this->Best_good_points();

}

