#ifndef FILE_PLAYER_H_INCLUDED
#define FILE_PLAYER_H_INCLUDED

#include <string>

class Player{
private:
    unsigned int _score;
    std::string _playerName;
public:
    Player(std::string);
    void addScore(unsigned int);
    std::string getName(std::string);
    unsigned int getScore();
};
#endif
