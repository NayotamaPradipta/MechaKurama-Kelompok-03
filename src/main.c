#include "func.h"
#include <stdio.h>

int main(){
    char Map[MAP_SIZE][MAP_SIZE]; // Inisialisasi map berukuran NxN
    Robot R;
    setupMap(Map);
    setupRobot(&R);
    Map[0][0] = R.logo; // Robot dimulai di koordinat 0,0
    displayMap(Map);
    
}