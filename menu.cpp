#include "data.h"
#include <iostream>
using namespace std;
void menuLogin(){
    cout << "==========================" << endl;
    cout << "      MENU LOGIN         " << endl;
    cout << "==========================" << endl;
    cout << "1. Login " << endl;
    cout << "2. register " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
}

void menuDasboard(){
    cout << "==========================" << endl;
    cout << "     MENU DASHBOARD      " << endl;
    cout << "==========================" << endl;
    cout << "1. list pengguna " << endl;
    cout << "2. total transaksi " << endl;
    cout << "3. menagemet sampah  " << endl;
    cout << "4. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

}

void menuPengguna(){
    cout << "==========================" << endl;
    cout << "      MENU PENGGUNA      " << endl;
    cout << "==========================" << endl;
    cout << "1. user " << endl;
    cout << "2. petugas" << endl;
    cout << "4. kembali " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

}
void menuManagemetSampah(){
    cout << "==========================" << endl;
    cout << "   MENU MANAGEMET SAMPAH " << endl;
    cout << "==========================" << endl;
    cout << "1. daftar ketegori " << endl;
    cout << "2. management titik pengumpulan " << endl;
    cout << "3. harga sampah " << endl;
    cout << "4. aturan pemilahan" << endl;
    cout << "5. kembali " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

}

