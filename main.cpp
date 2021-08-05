#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

#define ROWS 20
#define COLS 20

void connectNeighbourgs(Cell node[], int index);
int visitNeighbours(Cell &node);
void applyLogic(Cell &node);
void gameLogic(Cell nodes[]);

int main(){
    Cell nodes[ROWS*COLS];

    for(int i=0; i<ROWS*COLS; i++){
        nodes[i] = Cell();
    }

    for(int i=0; i<ROWS*COLS; i++){
        connectNeighbourgs(nodes,i);
    }

    nodes[40].m_currState = true;
    nodes[41].m_currState = true;
    nodes[42].m_currState = true;
    nodes[42-COLS].m_currState = true;
    nodes[42-2*COLS-1].m_currState = true;

    while(true){
        gameLogic(nodes);
        char input;
        scanf("%c",&input);
        if(input == 'q')break;
    }
}

//void arr2mat(int &i, int &j,int index){
//    i =
//}

void printBoard(Cell nodes[]){
    for(int i=0; i<ROWS*COLS; i++){
        if(i%COLS == 0)printf("\n");
        printf(nodes[i].m_currState ? "@" : "-");
    }
    //printf("\n");
}

void gameLogic(Cell nodes[]){
    system("clear");
    printBoard(nodes);
    printBoard(nodes);

    for(int i=0; i<ROWS*COLS; i++){
        applyLogic(nodes[i]);
    }

    for(int i=0; i<ROWS*COLS; i++){
        nodes[i].updateState();
    }
}

void applyLogic(Cell &node){
    int alive = visitNeighbours(node);
    
    if(node.m_currState){
        if(alive < 2){
            node.m_nextState = false;
        }else if(alive == 2 || alive == 3){
            node.m_nextState = true;
        }else if(alive > 3){
            node.m_nextState = false;
        }
        return;
    }
    node.m_nextState = alive == 3 ? true : false;
    
}
int visitNeighbours(Cell &node){
    int alive = 0;
    for(Cell *currCell:node.m_neighbours){
        alive += currCell->m_currState ? 1 : 0;
    }
    return alive;
}

void connectNeighbourgs(Cell nodes[], int index){
    int currI = index / ROWS;
    int currJ = index % COLS;

    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if(i==j && i==0)continue;
            int newI = (currI + i)%ROWS < 0?  ROWS + (currI + i)%ROWS : (currI + i)%ROWS;
            int newJ = (currJ + j)%COLS < 0?  COLS + (currJ + j)%COLS : (currJ + j)%COLS;
            int D = newI * COLS + newJ;
            nodes[index].createConection(&nodes[D]);
        }
    }
}

