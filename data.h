#ifndef data_h
#define data_h
#include <string>
using namespace std;

 int pilihan;

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
class createNode{
public:
    string data;
    createNode* firstChild;
    createNode* nextSibling;

    createNode(string value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

class deteleNode{
public:
    void deleteTree(createNode* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->firstChild);
        deleteTree(node->nextSibling);

        delete node;
    }
};




#endif