// Practical 4 This C program creates a linked list to store integer elements. It prompts the user to enter elements and add them to the list until the user enters 0. It then traverses the list and prints each element and "=>" until reaching the null pointer. Finally, it displays the number of nodes in the list.
#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
int main() {
struct Node *head = NULL;
struct Node *temp = NULL;
struct Node *newNode = NULL;
int num, count = 0;
printf("Enter elements (0 to stop): ");
while (1) {
scanf("%d", &num);
if (num == 0)
break;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = num;
newNode->next = NULL;
if (head == NULL)
head = newNode;
else
temp->next = newNode;
temp = newNode;
count++;
}
temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%d=>", temp->data);
temp = temp->next;
}
printf("NULL\nNumber of nodes: %d\n", count);
return 0;
}
