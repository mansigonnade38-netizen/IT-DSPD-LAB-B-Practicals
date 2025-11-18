// Practical 5 Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , Preorder and Post Order and Search an element in Binary Tree(Display NULL if not found, If found Display Found)

#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node* left;
struct node* right;
};

struct node* createNode(int value) {
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

struct node* createTree() {
int value;
printf("enter value of node (-1 to stop)");
scanf("%d", &value);
if (value == -1) {
return NULL;
}
struct node* root = createNode(value);
printf("enter value for left child of %d \n", value);
root->left = createTree();
printf("enter value for right child of %d \n", value);
root->right = createTree();
return root;
}

void inorder(struct node* root) {
if (root == NULL) {
return;
}
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}

void preorder(struct node* root) {
if (root == NULL) {
return;
}
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}

void postorder(struct node* root) {
if (root == NULL) {
return;
}
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}

int search(struct node* root, int key) {
if (root == NULL) {
return 0;
}
if (root->data == key) {
return 1;
}
return search(root->left, key) || search(root->right, key);
}

int main() {
struct node* root = createTree();
printf("Inorder: ");
inorder(root);
printf("\nPreorder: ");
preorder(root);
printf("\nPostorder: ");
postorder(root);
int key;
printf("\nEnter value to search: ");
scanf("%d", &key);
if (search(root, key)) {
printf("Found\n");
} else {
printf("Not Found\n");
}
return 0;
}
