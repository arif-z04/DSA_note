#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

    Node* insert(Node *root, int data){
        Node* newNode = new Node(data);
        if(root == NULL){
            root = newNode;
            return root;
        }
    }

};

int main(){


}