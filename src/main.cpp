#include "func.hpp"
#include <iostream>
using namespace std;

int main(){
    //SETUP SEBELUM GAME DIMULAI 

    char Map[MAP_SIZE][MAP_SIZE]; // Inisialisasi map berukuran NxN
    bool Quit = false;
    int Poin = 0;
    Robot R;
    MechaKurama MK;    
    setupMap(Map);
    setupRobot(&R, Map);
    setupMechaKurama(&MK, Map, R);

    

    //GAME

    while(R.health>0 && not Quit){
        displayMap(Map); //Menampilkan peta
        cout<<"Posisi Robot: ("<<R.X<<','<<R.Y<<')'<<endl; //Menampilkan posisi robot
        cout<<"Jarak Mecha-Kurama dengan robot: "<<getRange(R,MK)<<endl; //menampilkan jarak mecha-kurama dengan robot
        cout<< "Daftar Command: \n 1. Move \n 2. Attack \n 3.Quit \n \n Masukkan command (1/2/3): "<<endl; 

        //input command 
        int command;
        bool valid = false;
        
        while(not valid){ //validasi command
            cin>>command;
            if (command == 1 || command==2 || command==3){//input valid
                valid = true;
            } else{ //input tak valid
                cout<< "1. Move \n 2. Attack \n 3.Quit \n \n Masukkan command (1/2/3): "<<endl; 
            }
        }
        //Eksekusi Command
        if (command == 1){ //eksekusi command move
            int direction;
            
            cout<<"Daftar Arah: \n 1. Atas \n 2. Kanan \n 3. Bawah \n 4. Kiri \n \n Masukkan Arah(1/2/3/4): "<<endl;

            //validasi arah
            valid=false;

            do {
                cin>>direction;
                if (direction == 1 || direction == 2 || direction ==3 || direction==4){
                    valid = true;
                } else{
                    cout<<"Daftar Arah: \n 1. Atas \n 2. Kanan \n 3. Bawah \n 4. Kiri \n \n Masukkan Arah(1/2/3/4): "<<endl;
                }
            } while (not valid && !legalMove(R, Map, direction, MK));

            Move(&R,Map,direction, MK); //Pemanggilan fungsi Move
            attackRobot(&R, MK, Map); // Mecha Kurama akan menyerang jika dalam range
        } else if (command == 2){ //eksekusi command Attack
            attackMechaKurama(R,&MK,Map,&Poin); //pemanggilan fungsi attack
            attackRobot(&R, MK, Map); // Mecha Kurama akan melawan setelah robot menyerang (Jika dalam range)
        } else { //eksekusi command Quit
            Quit = true;
        }
    }


    //GAME SELESAI
    cout<<"=====Permainan Selesai====="<<endl;
    cout<<"Jumlah Bunshin Mecha-Kurama yang berhasil dikalahkan: "<<Poin<<endl;

    return 0;        
}
