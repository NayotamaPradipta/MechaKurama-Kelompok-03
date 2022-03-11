# Mecha Kurama-Kelompok-03
Tugas Besar Kelompok Divisi Programming 




### Alur Program <hr>
1. Pada awal program, robot akan mulai pada koordinat (0,0) dan satu bunshin Mecha-Kurama akan muncul secara random di koordinat manapun yang tidak sama dengan robot
2. Peta hanya berada pada kuadran pertama sumbu kartesian sehingga nilai koordinat selalu positif (tampilkan peta)
3. Robot akan meminta komando dari user untuk memilih apakah ingin bergerak atau menembak
4. Jika bunshin Mecha-Kurama berada di luar jangkauan senjata keluarkan pesan kesalahan. Robot akan berhenti saat program dihentikan oleh user atau saat health mencapai 0
5. Saat program dihentikan atau health mencapai 0 keluarkan jumlah bunshin Mecha-Kurama yang berhasil dikalahkan
6. Bunshin Mecha Kurama memiliki atribut health dan damage serangan juga

### Spesifikasi Robot 
1. Robot dapat membaca dan menampilkan posisinya saat ini
2. Robot selalu dimulai pada koordinat (0,0) saat program berjalan
3. Robot dapat bergerak satu satuan maju mundur, ke kanan atau ke kiri, setiap perintah bergerak dipanggil tetapi tidak dapat keluar dari peta dan menabrak Mecha-Kurama
4. Robot memiliki atribut health
5. Robot dapat menyerang Mecha-Kurama dengan damage yang konstan dan juga memiliki jarak maksimum untuk menyerang
6. Robot dapat menghitung jarak dengan Mecha-Kurama