// Header file
#ifndef _FUNC_H_
#define _FUNC_H_
#define MAP_SIZE 10
#include <iostream>

typedef struct {
    char logo;
    int X;
    int Y;
    int health;
    int damage;
    int range;
} Robot;

typedef struct {
    char logo;
    int X;
    int Y;
    int health;
    int damage;
    int range;
} MechaKurama;



// Fungsi untuk inisialisasi robot 
void setupRobot(Robot *r, char Map[][MAP_SIZE]);


// Fungsi untuk inisialisasi Mecha Kurama;
void setupMechaKurama(MechaKurama *MK, char Map[][MAP_SIZE], Robot r);

// Fungsi untuk inisialisasi map 
void setupMap(char Map[][MAP_SIZE]);

// Fungsi untuk display map
void displayMap(char Map[][MAP_SIZE]);

// Fungsi untuk mengecek apakah move legal atau tidak 
bool legalMove(Robot r, char Map[][MAP_SIZE], int command, MechaKurama MK);

// Fungsi untuk memindahkan posisi robot sesuai dengan command
void Move(Robot *r, char Map[][MAP_SIZE], int command);

// Fungsi untuk cek jarak robot dengan mecha kurama
float getRange(Robot r, MechaKurama MK);

// Fungsi mengembalikan true jika robot dapat menyerang MK
bool inRangeRobot(Robot r, MechaKurama MK);

// Fungsi mengembalikan true jika MK dapat menyerang robot 
bool inRangeMK(MechaKurama MK, Robot r);

// Fungsi untuk attack MechaKurama
void attackMechaKurama(Robot r, MechaKurama *MK, char MAP[][MAP_SIZE], int *Poin);

// Fungsi untuk menyerang Robot
void attackRobot(Robot *r, MechaKurama MK, char MAP[][MAP_SIZE]);



#endif
