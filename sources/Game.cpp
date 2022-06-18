#include "Game.hpp"


Game::Game(Team *In , Team *Out) : _In(In),_Out(Out){
    this->Pair_Result.first = 0;
    this->Pair_Result.second = 0;
    this->LaunchGame();
}

    void Game::normal_distribution(Team *In , Team *Out){
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> Result_distribution{Expectation ,Variance };
    // std::pair <unsigned int , unsigned int> Pair_Result;
    unsigned int Home_Result = 0;
    unsigned int Out_Result = 0 ;
    while(Home_Result >MAX_HOME_GOOD_POINTS || Home_Result < MIN_HOME_BAD_POINTS){Home_Result = (unsigned int)(round(Result_distribution(gen)));}
    while(Out_Result >MAX_OUT_GOOD_POINTS || Out_Result < MIN_OUT_BAD_POINTS){Out_Result = (unsigned int)(round(Result_distribution(gen)));}
    unsigned int Final_Home_result = Add_Bonus(In , Home_Result);
    unsigned int Final_Out_result = Add_Bonus(Out , Out_Result);
    this->Pair_Result.first = Final_Home_result;
    this->Pair_Result.second = Final_Out_result;
}

void Game::TeamWinner(Team *Winner ,Team *Losser, unsigned int Win , unsigned int Loss){
    Winner->update_good_points(Win);
    Winner->update_bad_points(Loss);
    Winner->update_win_streak();
    Winner->update_W();
    Game::TeamLosser(Losser , Win , Loss);
};

void Game::TeamLosser(Team *Losser , unsigned int Win , unsigned int Loss){
    Losser->update_good_points(Loss);
    Losser->update_bad_points(Win);
    Losser->update_loss_streak();
    Losser->update_L();
}

void Game::GameResult(unsigned int In , unsigned int Out){
    (In > Out)?this->TeamWinner(this->_In ,this->_Out, In , Out): this->TeamWinner(this->_Out , this->_In, Out , In);
    
}

unsigned int Game::Add_Bonus(Team *T ,unsigned int &Team_Bonus){unsigned int Res = (unsigned int)(T->get_t() * Tale);return Res + Team_Bonus;  }

void Game::LaunchGame(){
    if(this->_In==this->_Out){throw std::runtime_error("error");}
    this->normal_distribution(this->_In , this->_Out);
    this->GameResult(this->Pair_Result.first , this->Pair_Result.second);
}

std::pair<unsigned int , unsigned int>& Game::get_res(){return this->Pair_Result;}

