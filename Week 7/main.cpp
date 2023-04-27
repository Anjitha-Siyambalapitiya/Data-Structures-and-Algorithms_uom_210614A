#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root != NULL){
        traverseInOrder(root->left);
        cout << root->key << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if(node == NULL){
        struct node *current = (struct node *)malloc(sizeof(struct node));
        current->key = key;
        current->left = current->right = NULL;
        return current;
    }
    if (key < node->key){
        node->left = insertNode(node->left, key);
    }
    else{
        node->right = insertNode(node->right, key);
    }
    return node;
}

//for a given BST find the minimum key value
struct node* minValue(struct node* node) {
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == nullptr) {
        cout << "No item found to delete";
        return nullptr;
    }
    if(key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->right == nullptr and root->left == nullptr){
            return nullptr;
        }
        else if(root->left == nullptr){
            struct node* current = root->right;
            free(root);
            return current;
        }
        else if(root->right == nullptr){
            struct node* current = root->left;
            free(root);
            return current;
        }
        struct node* current = minValue(root->right);
        root->key = current->key;

        root->right = deleteNode(root->right, current->key);
    }
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}