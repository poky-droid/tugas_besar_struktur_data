#ifndef CRUD_H
#define CRUD_H
using namespace std;
#include <iostream>
#include "data.h"

Node* createData(Tree &t, Node* parent);
void readData(Node* node);
Node* searchData(Node* node); //pake username??
bool updateData(Node* root, string username);
bool deleteData(Tree &t, Node* parent, string username);

#endif