#include "ship.h"

Ship::Ship(unsigned int siz):
    _shipSize(siz),_floatin(true),_damage(0) {

}
unsigned int Ship::getSize(){
    return this->_shipSize;
}

void Ship::aHit(){
    this->_damage += 1;
    if(((this->_shipSize) - (this->_damage)) == 0){
        this->_floatin = false;
    }
}
