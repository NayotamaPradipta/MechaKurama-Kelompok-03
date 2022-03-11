#include "func.h"
#include <stdio.h>
// File untuk implementasi fungsi 



void displayMap(char Map[][MAP_SIZE]){
    printf("Map: \n");
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            printf("%c ", Map[i][j]);
        }
        printf("\n");
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