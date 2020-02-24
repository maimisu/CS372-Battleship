#ifndef FILE_PLAYER_H_INCLUDED
#define FILE_PLAYER_H_INCLUDED

#include <string>

class Player{
public:
    Player(std::string);
    Player(const Player& copy_from_me) = delete;
    Player & operator= (const Player & other) = delete;
    ~Player();
    void addScore(unsigned int);
    std::string getName(std::string);
    unsigned int getScore();
private:
    std::string _playerName;
    unsigned int _score;
};
#endif
