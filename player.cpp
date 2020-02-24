#include <string>
#include "player.h"

Player::Player(std::string str): _playerName(str),_score(0){
    //make ships associated with this class
    //make something to hold the position of those ships
}

void Player::addScore(unsigned int shipLeng){
    this->_score += shipLeng;
}

std::string Player::getName(std::string){
    return this->_playerName;
}
unsigned int Player::getScore(){
    return this->_score;
}
