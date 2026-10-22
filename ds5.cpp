#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
Node* makeNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
Node* insertNode(Node* root, int value) {
    if (root == NULL) return makeNode(value);
 
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
 
    return root;
}
 
int treeHeight(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}
 
Node* findMinimum(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
 
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
void mirrorTree(Node* root) {
    if (root == NULL) return;
 
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
 
    mirrorTree(root->left);
    mirrorTree(root->right);
}
 
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
 
int main() {
    Node* root = NULL;
    int n, value;
 
    cout << "Enter number of nodes: ";
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        root = insertNode(root, value);
    }
 
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
 
    cout << "Enter a value to insert: ";
    cin >> value;
    root = insertNode(root, value);
 
    cout << "Tree after insertion: ";
    inorder(root);
    cout << endl;
 
    cout << "Height of tree: " << treeHeight(root) << endl;
 
    Node* smallest = findMinimum(root);
    if (smallest != NULL)
        cout << "Minimum value: " << smallest->data << endl;
 
    mirrorTree(root);
    cout << "Mirror tree inorder: ";
    inorder(root);
    cout << endl;
 
    deleteTree(root);
    return 0;
}
