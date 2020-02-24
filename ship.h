#ifndef FILE_SHIP_H_INCLUDED
#define FILE_SHIP_H_INCLUDED


class Ship{
public:
    Ship(unsigned int);
    ~Ship();
    unsigned int getSize();
    void aHit();
private:
    bool floatin;
    unsigned int _shipSize;
};

#endif
