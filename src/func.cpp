#include "func.hpp"
#include <iostream>
#include <time.h>
#include <cmath>
// File untuk implementasi fungsi 

using namespace std;


void displayMap(char Map[][MAP_SIZE]){
    printf("Map: \n");
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            cout << Map[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

void setupRobot(Robot *r, char Map[][MAP_SIZE]){
    r->logo = 'R';
    r->X = 9; // Robot dimulai di koordinat 0,0 (catatan: koordinat 0,0 kartesian akan muncul sebagai [9][0] pada matriks 10x10)
    r->Y = 0;
    r->health = 100; // Masih asal-asalan
    r->damage = 20; // Masih asal-asalan 
    r->range = 3; // Masih asal-asalan
    r->MKDefeated = 0; // Pada awalnya robot belum mengalahkan Mecha Kurama
    Map[r->X][r->Y] = r->logo;
}




void setupMechaKurama(MechaKurama *MK, char Map[][MAP_SIZE], Robot r){
    int X = r.X;
    int Y = r.Y;
    srand(time(NULL));
    while (X == r.X && Y == r.Y){
        X = (rand() % 10);
        Y = (rand() % 10);
    }
    MK->X = X;
    MK->Y = Y;
    MK->logo = 'K';
    MK->health = 100;
    MK->damage = 5;
    MK->range = 2;
    Map[MK->X][MK->Y] = MK->logo;
}

void setupMap(char Map[][MAP_SIZE]){
    // Belum fix
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            Map[i][j] = '-';
        }
    }
}


void attackMechaKurama(Robot r, MechaKurama *MK, char MAP[][MAP_SIZE]){
    if (inRangeRobot(r, *MK)){
        MK->health -= r.damage;
    }
    if (MK->health <= 0){
        MAP[MK->X][MK->Y] = '-';
    }
}

bool legalMove(Robot r, char Map[][MAP_SIZE], int command, MechaKurama MK){
    if (command == 1){
        if (r.X == 0 || (r.X-1 == MK.X && r.Y == MK.Y)){
            return false;
        } else {
            return true;
        }
    } else if (command == 2 || (r.Y+1 == MK.Y && r.X == MK.X)){
        if (r.Y == 9){
            return false;
        } else {
            return true;
        }
    } else if (command == 3){
        if (r.X == 9 || (r.X+1 == MK.X && r.Y == MK.Y)){
            return false;
        } else {
            return true;
        }
    } else {
        if (r.Y == 0 || (r.Y-1 == MK.Y && r.X == MK.X)){
            return false;
        } else {
            return true;
        }
    }
}

void Move(Robot *r, char Map[][MAP_SIZE], int command){
    /* I.S Move sudah legal
       F.S Posisi robot terupdate, Map terupdate sesuai command */
    if (command == 1) {
        Map[r->X][r->Y] = '-';
        r->X -= 1;
        Map[r->X][r->Y] = r->logo;
        
    } else if (command == 2){
        Map[r->X][r->Y] = '-';
        r->Y += 1;
        Map[r->X][r->Y] = r->logo;
    } else if (command == 3){
        Map[r->X][r->Y] = '-';
        r->X += 1;
        Map[r->X][r->Y] = r->logo;
    } else {
        Map[r->X][r->Y] = '-';
        r->Y -= 1;
        Map[r->X][r->Y] = r->logo;
    }
 
}

int getRange(Robot r, MechaKurama MK){
    // ini apaa wkwk
    return (sqrt(pow((MK.X - r.X),2) + pow((MK.Y - r.Y),2)));
}

bool inRangeRobot(Robot r, MechaKurama MK){
    return (getRange(r,MK) <= 3);
}


bool inRangeMK(MechaKurama MK, Robot r){
    return (getRange(r,MK) <= 2);
}   

void attackRobot(Robot *r, MechaKurama MK, char MAP[][MAP_SIZE]){
    if (inRangeMK(MK, *r)){
        r->health -= MK.damage;
    }
    if (r->health <= 0){
        MAP[r->X][r->Y] = '-';
    }
}




