#include <iostream>
#include "data.h"
#include "pengelolaan_sampah.h"
using namespace std;

// Hitung total warga (role = user)
int countTotalWarga(nodeDataUser* head) {
    int count = 0;
    nodeDataUser* temp = head;

    while (temp != nullptr) {
        if (temp->data.role == "user") {
            count++;
        }
        temp = temp->next;
    }
    return count;
}


// Hitung total petugas (role = petugas)
int countTotalPetugas(nodeDataUser* head) {
    int count = 0;
    nodeDataUser* temp = head;

    while (temp != nullptr) {
        if (temp->data.role == "petugas") {
            count++;
        }
        temp = temp->next;
    }
    return count;
}


// Hitung volume sampah bulan ini (berat total)
double countVolumeSampahBulanIni(queueNode* head) {
    double total = 0;
    queueNode* temp = head;

    while (temp != nullptr) {
        total += temp->data.berat;
        temp = temp->next;
    }
    return total;
}


// MENU DASHBOARD
void dashboard(nodeDataUser* headUser, queueNode* headSampah) {
    cout << "\n======================================" << endl;
    cout << "           DASHBOARD SISTEM           " << endl;
    cout << "======================================" << endl;

    int totalWarga = countTotalWarga(headUser);
    int totalPetugas = countTotalPetugas(headUser);
    double totalVolume = countVolumeSampahBulanIni(headSampah);

    cout << "Total Warga Terdaftar      : " << totalWarga << endl;
    cout << "Total Petugas Terdaftar    : " << totalPetugas << endl;
    cout << "Volume Sampah Bulan Ini    : " << totalVolume << " kg" << endl;

    cout << "======================================\n" << endl;
}
