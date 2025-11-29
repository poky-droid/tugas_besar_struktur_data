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

int menuDasboard(){
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
    return pilihan;

}