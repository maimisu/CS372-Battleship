#ifndef FILE_SHIP_H_INCLUDED
#define FILE_SHIP_H_INCLUDED


class Ship{
public:
    Ship();
    Ship(unsigned int);
    unsigned int getSize();
    void aHit();
    bool aFloat();
private:
    unsigned int _shipSize;
    bool _floatin;
    int _damage;
};

#endif
