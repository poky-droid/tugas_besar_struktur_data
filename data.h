#ifndef DATA_H
#define DATA_H
#include <string>
#include "pengelolaan_sampah.h"
using namespace std;
extern int pilihan;

// Struktur data user/petugas
struct DataUser {
    string username;
    string password;
    string nama;
    string alamat;
    string no_telp;
    string role;
};

struct nodeDataUser
{
    DataUser data;
    nodeDataUser* next;
    nodeDataUser* prev;

};

void printUser(DataUser D);
DataUser inputUser(DataUser in);       // khusus input petugas
nodeDataUser* createNode();            // membuat node baru
nodeDataUser* deleteUser(nodeDataUser* head); // hapus user
nodeDataUser* editData(nodeDataUser* head);


void login(nodeDataUser* head);
string registerUser();
void menuAdmin();
void menuPetugas();
void menuDasboard();
int MenuUtama();

nodeDataUser* findUser(nodeDataUser* head, string username);


void menuUser();
struct nodeDataUser;
nodeDataUser* createNode();
void printUser(DataUser D);

extern nodeDataUser* headUser;



#endif
