#include "ship.h"

Ship::Ship():
    _shipSize(1),_floatin(true),_damage(0) {
}
Ship::Ship(unsigned int siz):
    _shipSize(siz),_floatin(true),_damage(0) {
        if (this->_shipSize <= 0){
            this->_floatin = false;
        }
}
unsigned int Ship::getSize(){
    return this->_shipSize;
}
void Ship::aHit(){
    if(this->_floatin){
    this->_damage += 1;
    if(((this->_shipSize) - (this->_damage)) == 0){
        this->_floatin = false;
    }
    }
}
bool Ship::aFloat(){
    return this->_floatin;
}
