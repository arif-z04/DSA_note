#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value){
        data = value;
        left = NULL;
        right = NULL;
    }
    
    // function : insert (Inserts level by level)
    Node* insert(Node* root, T value) {
        Node* newNode = new Node(value);
        if (root == NULL) {
            return newNode;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left != NULL) {
                q.push(temp->left);
            } else {
                temp->left = newNode;
                return root;
            }

            if (temp->right != NULL) {
                q.push(temp->right);
            } else {
                temp->right = newNode;
                return root;
            }
        }
        return root;
    }

    // function : inorder_recursive (Left -> Root -> Right)
    void inorder_recursive(Node* root) {
        if (root == NULL) return;
        inorder_recursive(root->left);
        cout << root->data << " ";
        inorder_recursive(root->right);
    }

    // function : inorder_iterative
    void inorder_iterative(Node* root) {
        stack<Node*> s;
        Node* curr = root;

        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    // function : postOrder_recursive (Left -> Right -> Root)
    void postOrder_recursive(Node* root) {
        if (root == NULL) return;
        postOrder_recursive(root->left);
        postOrder_recursive(root->right);
        cout << root->data << " ";
    }

    // function : postOrder_iterative
    void postOrder_iterative(Node* root) {
        if (root == NULL) return;
        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left != NULL) s1.push(temp->left);
            if (temp->right != NULL) s1.push(temp->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    // function : preOrder_recursive (Root -> Left -> Right)
    void preOrder_recursive(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder_recursive(root->left);
        preOrder_recursive(root->right);
    }

    // function : preOrder_iterative
    void preOrder_iterative(Node* root) {
        if (root == NULL) return;
        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            cout << temp->data << " ";

            if (temp->right != NULL) s.push(temp->right);
            if (temp->left != NULL) s.push(temp->left);
        }
    }

    // function : levelOrderTraversal (Breadth-First Search)
    void levelOrderTraversal(Node* root) {
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
    }
};

int main(){
    // Create a dummy node to access the member functions
    Node<int>* treeHelper = new Node<int>(0);
    Node<int>* root = NULL;

    // Insert elements to build a simple tree
    root = treeHelper->insert(root, 10);
    root = treeHelper->insert(root, 20);
    root = treeHelper->insert(root, 30);
    root = treeHelper->insert(root, 40);
    root = treeHelper->insert(root, 50);

    cout << "Pre-order Recursive:  ";
    treeHelper->preOrder_recursive(root);
    cout << "\nPre-order Iterative:  ";
    treeHelper->preOrder_iterative(root);
    cout << "\n\n";

    cout << "In-order Recursive:   ";
    treeHelper->inorder_recursive(root);
    cout << "\nIn-order Iterative:   ";
    treeHelper->inorder_iterative(root);
    cout << "\n\n";

    cout << "Post-order Recursive: ";
    treeHelper->postOrder_recursive(root);
    cout << "\nPost-order Iterative: ";
    treeHelper->postOrder_iterative(root);
    cout << "\n\n";

    cout << "Level-order Traversal: ";
    treeHelper->levelOrderTraversal(root);
    cout << "\n";

    return 0;
}
