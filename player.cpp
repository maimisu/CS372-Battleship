#include <string>
#include "player.h"
#include "ship.h"

Player::Player(std::string str): _playerName(str),_score(0){
    /*Ship carrier((unsigned int)5);
    Ship battleship((unsigned int)4);
    Ship cruiser((unsigned int)3);
    Ship submarine((unsigned int)3);
    Ship rowboat((unsigned int)2);*/
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
