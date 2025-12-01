#include "pengelolaan_sampah.h"
#include "data.h"
#include "crud.h"
#include <iostream>
using namespace std;

int main() {
    Data d;          
    
    int menulogin(d);   
    // Cek role dari user
    if (d.role == "admin") {
    } 
    else if (d.role == "petugas") {
    } 
    else if (d.role == "user") {
    } 
    else {
        cout << "Role tidak dikenali." << endl;
    }

    return 0;
}
