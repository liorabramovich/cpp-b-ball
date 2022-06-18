#include "Schedule.hpp"


Schedule::Schedule(vector<Team*> &S_League) {this->_S_League = S_League;

    this->GeneratorGames();

}

void Schedule::GeneratorGames(){
    int counter = 0;
    int v = 0;
    while(counter < 2){
        for(unsigned int i = 0 ; i < this->_S_League.size()-1;i++){
            unsigned int j = 0;
            unsigned int team_size = this->_S_League.size()-1;
            while(j<Games_10){
                // std::cout << "Game NUmber : " << v++ <<std::endl;
                if(counter==1){Game ga{this->_S_League.at(team_size),this->_S_League.at(j)};}

                if(counter ==0){ Game ga{this->_S_League.at(j),this->_S_League.at(team_size)};
                }
                j++;
                team_size--;
            }
            this->_S_League.insert(this->_S_League.begin() + 1, *(this->_S_League.erase(this->_S_League.end() - 1)));

        }

        counter++;
    }

}


