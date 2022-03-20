#include "func.hpp"
#include <iostream>
// File untuk implementasi fungsi 

using namespace std;

void displayMap(char Map[][MAP_SIZE]){
    printf("Map: \n");
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            cout << Map[i][j];
        }
        cout << endl;
    }
}

void setupRobot(Robot *r){
    r->logo = 'R';
    r->X = 0;
    r->Y = 0;
    r->health = 100; // Masih asal-asalan
    r->damage = 20; // Masih asal-asalan 
    r->range = 2; // Masih asal-asalan
}

void setupMechaKurama(MechaKurama *MK, char Map[][MAP_SIZE]){

}

void setupMap(char Map[][MAP_SIZE]){
    // Belum fix
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            Map[i][j] = '-';
        }
    }
}

void attackMechaKurama(Robot r, MechaKurama *MK, char MAP[][MAP_SIZE]);{
    if (inRangeRobot(r, *MK)){
        MK->health -= r.damage;
    }
    if (MK->health <= 0){
        MAP[MK->X][MK->Y] = '-';
    }
}
