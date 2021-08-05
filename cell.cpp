#include "cell.h"

Cell::Cell():
    m_currState(false),
    m_nextState(false){};

void Cell::updateState(){
    this->m_currState = this->m_nextState;
}

void Cell::createConection(Cell *node){
    this->m_neighbours.push_back(node);
}
