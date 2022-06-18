#include "sources/League.hpp"
using namespace std;
int main(){
string input ;
string team_name;
double team_tal;
int flag = 1;
vector<Team*>Teams;

while(flag){
    cout << "1 - generate random league  , 2 - Add a team , 3 - start league , 4 - Quit"<<endl;
    try{
    cin >> input;
    
    if(input == "1"){
        League L{};
        L.Play();
        L.statistical_analysis(5);
    }
    if(input == "2"){
        cout << "Team Name : "<<endl;
        cin >> team_name;
        cout << "enter a talent"<<endl;
        cin >>team_tal;
        Team *t = new Team(team_name , team_tal);
        Teams.push_back(t);
    }

    if(input == "3"){
        League L2{Teams};
        L2.Play();        
    }

    if(input == "Quit"){
        flag = 0;   
    }
    }  catch (std::exception &ex)
     {
         std::cout << "caught exception: " << ex.what() << std::endl;
     }
}
    
}