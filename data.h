#ifndef data_h
#define data_h
#include <string>
using namespace std;

class Node {
public:
    std::string data;     
    Node* firstChild;     
    Node* nextSibling;    

    Node(std::string value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void createRoot(std::string value) {
        root = new Node(value);
    }

    Node* addChild(Node* parent, std::string value) {
        Node* newNode = new Node(value);

        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        } else {
            Node* temp = parent->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = newNode;
        }
        return newNode;
    }
};




#endif