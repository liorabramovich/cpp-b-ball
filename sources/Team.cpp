#include "Team.hpp"


Team::Team(string &name , double t):_name(name),_t(t){
    this->_teamscoreboard.first = 0; 
    this->_teamscoreboard.second = 0;
    this->_good_points = 0;
    this->_bad_points = 0;
    this->Over_80 = 0;
    this->_team_streak="";
    if(this->_t > 1 || this->_t < 0){throw std::range_error("talent must be between 0 and 1");}
    
}
double Team::get_t()const{return this->_t;}
string Team::get_Team_name(){return this->_name;}
int Team::remainder()const{return (int)this->_good_points-(int)this->_bad_points;}
unsigned int Team::get_W()const{return this->_teamscoreboard.first;}
unsigned int Team::get_L()const{return this->_teamscoreboard.second;}
unsigned int Team::get_win_streak(){return this->getMaxTeamStreak('L');}
unsigned int Team::get_loss_streak(){return this->getMaxTeamStreak('W');}
unsigned int Team::get_good_points()const{return this->_good_points;}
unsigned int Team::get_bad_points()const{return this->_bad_points;}
unsigned int Team::get_Over_80()const{return this->Over_80;}
void Team::update_W(){this->_teamscoreboard.first++;}
void Team::update_L(){this->_teamscoreboard.second++;}
void Team::update_win_streak(){this->_team_streak.append("W");}
void Team::update_loss_streak(){this->_team_streak.append("L");}
void Team::update_good_points(unsigned int x){this->_good_points+=x;if(x>=scored_80){Over_80++;}}
void Team::update_bad_points(unsigned int x){this->_bad_points+=x;}
void Team::print(){std::cout <<" Name:"<<this->get_Team_name()<< " ,Wins: "<<this->get_W()<<" ,Loss: " << this->get_L()<<
        " ,good_points: "<<get_good_points()<<" ,bad_points: "<<this->get_bad_points()<<" ,remainder: "<<this->remainder()<<std::endl;}
unsigned int Team::getMaxTeamStreak(char X){unsigned int count = 0;unsigned int res = 0;for(char c : this->_team_streak){if(c==X){count = 0;}else{count++;res=max(res,count);}}return res;}
     
     
     
         
         
         

    

    




// int main(){
//     string t1 = "Ba";
//     Team *t = new Team(t1, 0.2);
//     t->update_win_streak();
//     t->update_loss_streak();
//     t->update_W();
//     t->update_L();

//     cout << t->get_t()<<endl;
//     cout << t->get_L()<<endl;
//     cout << t->get_W()<<endl;
//     cout << t->get_win_streak()<<endl;
//     cout << t->get_loss_streak()<<endl;

// }