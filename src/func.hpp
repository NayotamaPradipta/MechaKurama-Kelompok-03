// Header file
#ifndef _FUNC_H_
#define _FUNC_H_
#define MAP_SIZE 5

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
} MechaKurama;


// Fungsi untuk inisialisasi robot 
void setupRobot(Robot *r);

// Fungsi untuk inisialisasi Mecha Kurama;
void setupMechaKurama(MechaKurama *MK, char Map[][MAP_SIZE]);

// Fungsi untuk inisialisasi map 
void setupMap(char Map[][MAP_SIZE]);

// Fungsi untuk display map
void displayMap(char Map[][MAP_SIZE]);

// Fungsi untuk memindahkan posisi robot sesuai dengan command
void Move(Robot r, char Map[][MAP_SIZE], char command);

// Fungsi untuk attack MechaKurama
void attackMechaKurama(Robot r, MechaKurama *MK, char MAP[][MAP_SIZE]);

// Fungsi untuk cek jarak robot dengan mecha kurama
int getRange(Robot r, MechaKurama MK);

#endif