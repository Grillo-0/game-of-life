#include "cell.h"

Cell::Cell():
    m_currrState(false),
    m_nextState(false){};

void Cell::updateState(){
    this->m_currrState = this->m_nextState;
}
