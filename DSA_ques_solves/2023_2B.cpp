#include <iostream>
using namespace std;

// Definition of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Pre-order Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";   // Visit root
    preorder(root->left);         // Traverse left subtree
    preorder(root->right);        // Traverse right subtree
}

// In-order Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return;
    
    inorder(root->left);          // Traverse left subtree
    cout << root->data << " ";    // Visit root
    inorder(root->right);         // Traverse right subtree
}

// Post-order Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    
    postorder(root->left);        // Traverse left subtree
    postorder(root->right);       // Traverse right subtree
    cout << root->data << " ";    // Visit root
}

int main() {
    // Constructing the tree from the image:
    //            1
    //           / \
    //          12   9
    //         /  \
    //        5    6
    
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    
    cout << "Tree Structure:\n";
    cout << "         1\n";
    cout << "        / \\\n";
    cout << "       12   9\n";
    cout << "      /  \\\n";
    cout << "     5    6\n\n";
    
    cout << "Pre-order Traversal  (Root -> Left -> Right): ";
    preorder(root);
    cout << endl;
    
    cout << "In-order Traversal   (Left -> Root -> Right): ";
    inorder(root);
    cout << endl;
    
    cout << "Post-order Traversal (Left -> Right -> Root): ";
    postorder(root);
    cout << endl;
    
    return 0;
}