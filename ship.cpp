#include "ship.h"

Ship::Ship(unsigned int siz):
    _shipSize(siz),floatin(true) {

}
unsigned int Ship::getSize(){
    return this->_shipSize;
}
