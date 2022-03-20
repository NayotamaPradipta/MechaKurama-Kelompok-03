#include "func.hpp"
#include <iostream>
#include <time.h>
#include <cmath>
// File untuk implementasi fungsi 

using namespace std;

//Prosedur untuk menampilkan Map 
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

//Prosedur untuk melakukan setup robot
void setupRobot(Robot *r, char Map[][MAP_SIZE]){ 
    r->logo = 'R';
    r->X = 9; // Robot dimulai di koordinat 0,0 (catatan: koordinat 0,0 kartesian akan muncul sebagai [9][0] pada matriks 10x10)
    r->Y = 0;
    r->health = 100; 
    r->damage = 20; 
    r->range = 5; 
    Map[r->X][r->Y] = r->logo; // Tampilan Map pada koordinat robot diganti menjadi logo robot
}

//Prosedur untuk melakukan setup Mecha-Kurama
void setupMechaKurama(MechaKurama *MK, char Map[][MAP_SIZE], Robot r){
    int X = r.X;
    int Y = r.Y;
    srand(time(NULL));
    while (X == r.X && Y == r.Y){ //Setup agar posisi Mecha-Kurama sesuai ketentuan
        X = (rand() % 10);
        Y = (rand() % 10);
    }
    MK->X = X;
    MK->Y = Y;
    MK->logo = 'K';
    MK->health = 100;
    MK->damage = 5;
    MK->range = 4;
    Map[MK->X][MK->Y] = MK->logo; // Tampilan Map pada koordinat Mecha-Kurama diganti menjadi logonya
}

// Prosedur setup Map sebelum ada robot dan Mecha-Kurama
void setupMap(char Map[][MAP_SIZE]){ 

    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            Map[i][j] = '-'; // elemen pada Map diberi default '-'
        }
    }
}

//Prosedur untuk menyerang Mecha-Kurama
void attackMechaKurama(Robot r, MechaKurama *MK, char MAP[][MAP_SIZE], int *Poin){
    if (inRangeRobot(r, *MK)){ //Jika Mecha-Kurama masuk jangkauan serangan robot
        MK->health -= r.damage;
        cout<<"Berhasil menyerang Mecha-Kurama \n HP Mecha-Kurama: "<<MK->health<<endl;
    } else{ //tidak masuk
        cout<<"Mecha-Kurama tidak masuk dalam jangkauan serangan(range:"<<r.range<<")"<<endl;
    }
    if (MK->health <= 0){ //Jika Mecha-Kurama berhasil dikalahkan
        MAP[MK->X][MK->Y] = '-';
        *Poin += 1;
        cout<<"Mecha-Kurama Berhasil dikalahkan!"<<endl;
        setupMechaKurama(MK, MAP, r); //Spawn Mecha-Kurama baru
        cout<<"Mecha-Kurama yang baru Muncul!"<<endl;
    }
}

//Fungsi untuk mengecek apakah gerakan robot diperbolehkan
bool legalMove(Robot r, char Map[][MAP_SIZE], int command, MechaKurama MK){
    if (command == 1){ //Atas
        return  !(r.X == 0 || (r.X-1 == MK.X && r.Y == MK.Y));
    } else if (command == 2 ){//Kanan
        return !(r.Y == 9 || (r.Y+1 == MK.Y && r.X == MK.X));
    } else if (command == 3){//Bawah
        return !(r.X == 9 || (r.X+1 == MK.X && r.Y == MK.Y));
    } else {//Kiri
        return !(r.Y == 0 || (r.Y-1 == MK.Y && r.X == MK.X));
    }
}


//Prosedur Robot Bergerak
void Move(Robot *r, char Map[][MAP_SIZE], int command){
    /* I.S Move sudah legal
       F.S Posisi robot terupdate, Map terupdate sesuai command */
    if (command == 1) {//Atas
        Map[r->X][r->Y] = '-';
        r->X -= 1;
        Map[r->X][r->Y] = r->logo;
        
    } else if (command == 2){//Kanan
        Map[r->X][r->Y] = '-';
        r->Y += 1;
        Map[r->X][r->Y] = r->logo;
    } else if (command == 3){//Bawah
        Map[r->X][r->Y] = '-';
        r->X += 1;
        Map[r->X][r->Y] = r->logo;
    } else {//Kiri
        Map[r->X][r->Y] = '-';
        r->Y -= 1;
        Map[r->X][r->Y] = r->logo;
    }
 
}

//Fungsi untuk menghitung jarak robot dengan Mecha-Kurama (Jarak Euclidean)
float getRange(Robot r, MechaKurama MK){
    return (sqrt(pow((MK.X - r.X),2) + pow((MK.Y - r.Y),2)));;
}

//Fungsi untuk mengecek apakah MechaKurama berada di dalam jangkauan serangan robot
bool inRangeRobot(Robot r, MechaKurama MK){
    return (getRange(r,MK) <= r.range);
}

//Fungsi untuk mengecek apakah Robot berada di dalam jangkauan serangan Mecha Kurama
bool inRangeMK(MechaKurama MK, Robot r){
    return (getRange(r,MK) <= MK.range);
}   

//Prosedur Mecha Kurama menyerang robot
void attackRobot(Robot *r, MechaKurama MK, char MAP[][MAP_SIZE]){
    if (inRangeMK(MK, *r)){ //Jika Robot dalam jangkauan serangan Mecha Kurama
        r->health -= MK.damage;
        cout<<"Robot Diserang!! \n HP Robot: "<<r->health<<endl;
    } else{ // Jika tidak
        cout<<"Robot tidak terkena serangan Mecha-Kurama(range:"<<MK.range<<")"<<endl;
    }
    if (r->health <= 0){ //Jika robot dikalahkan oleh Mecha Kurama
        MAP[r->X][r->Y] = '-';
        cout<<"Robot dikalahkan :("<<endl;
    }
}


