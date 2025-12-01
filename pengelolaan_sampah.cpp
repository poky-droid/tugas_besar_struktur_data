#include "pengelolaan_sampah.h"
#include <iostream>
using namespace std;

queueNode* createSampah(Sampah S){
    queueNode* newNode = new queueNode;
    newNode -> data = S;
    newNode -> next = nullptr;
    return newNode;
}
bool isEmpty(){
    return depan == nullptr;
}

void enqueueSampah (Sampah S){
    queueNode* newNode = createSampah(S);
    if (isEmpty()){
        depan = newNode;
        belakang = newNode;
    } else {
        belakang -> next = newNode;
        belakang = newNode;
    }
}

string dequeueSampah(Sampah S){
    if (isEmpty()){
        return "Queue kosong, tidak ada sampah untuk diambil.";
    } else {
        queueNode* temp = depan;
        string jenis = depan -> data.jenisSampah;
        depan = depan -> next;
        delete temp;
        return jenis + " telah diambil dari antrian.";
    }
}

void tampilQueueSampah(){
    if (isEmpty()){
        cout << "Queue kosong." << endl;
    } else {
        queueNode* current = depan;
        cout << "Antrian Sampah: " << endl;
        while (current != nullptr){
            cout << "- Jenis: " << current -> data.jenisSampah
                 << ", Berat(kg): " << current -> data.berat 
                 << ", Harga per Kg: Rp " << current -> data.hargaPerKg << endl;
            current = current -> next;
        }
    }
}
