// Practical 6 Implement Binary search tree(BST) with following Menu operations. 1.​Search an element in BST(Display NULL if not found, If found Display Found) 2.​Insert an element in BST 3.​Delete leaf element in BST 4.​Exit

#include <stdio.h>
#include <stdlib.h>
struct node {
int key;
struct node *left, *right;
};
struct node* newNode(int key) {
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->key = key;
temp->left = temp->right = NULL;
return temp;
}
struct node* insert(struct node* node, int key) {
if (node == NULL) return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
return node;
}
struct node* search(struct node* root, int key) {
if (root == NULL || root->key == key)
return root;
if (key < root->key)
return search(root->left, key);
return search(root->right, key);
}
int isLeaf(struct node* node) {
return (node->left == NULL && node->right == NULL);
}
struct node* deleteLeaf(struct node* root, int key) {
if (root == NULL) return NULL;
if (key < root->key)
root->left = deleteLeaf(root->left, key);
else if (key > root->key)
root->right = deleteLeaf(root->right, key);
else {
if (isLeaf(root)) {
free(root);
return NULL;
} else {
printf("Not a leaf node, cannot delete\n");
}
}
return root;
}
int main() {
struct node* root = NULL;
int choice, key;
while (1) {
printf("1. Search an element in BST\n");
printf("2. Insert an element in BST\n");
printf("3. Delete leaf element in BST\n");
printf("4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice == 1) {
printf("Enter element to search: ");
scanf("%d", &key);
struct node* found = search(root, key);
if (found)
printf("Found\n");
else
printf("NULL\n");
} else if (choice == 2) {
printf("Enter element to insert: ");
scanf("%d", &key);
root = insert(root, key);
} else if (choice == 3) {
printf("Enter leaf element to delete: ");
scanf("%d", &key);
root = deleteLeaf(root, key);
} else if (choice == 4) {
break;
} else {
printf("Invalid choice\n");
}
}
return 0;
}
