#include <stdio.h> 
#include <stdlib.h> 

#define MAX_SIZE 100 

int queue[MAX_SIZE]; 
int front = -1, rear = -1; 

void enqueue(int value); 
int dequeue(); 
void display(); 

int main() { 
    enqueue(10); 
    enqueue(20); 
    enqueue(30); 

    display(); 

    dequeue(); 

    display(); 

    return 0; 
} 

void enqueue(int value) { 
    if (rear == MAX_SIZE - 1) { 
        printf("Queue is full.\n"); 
    } else { 
        if (front == -1) { 
            front = 0; 
        } 
        rear++; 
        queue[rear] = value; 
    } 
} 

int dequeue() { 
    int element; 
    if (front == -1) { 
        printf("Queue is empty.\n"); 
        return -1; 
    } else { 
        element = queue[front]; 
        front++; 
        if (front > rear) { 
            front = rear = -1; 
        } 
        return element; 
    } 
} 

void display() { 
    if (front == -1) { 
        printf("Queue is empty.\n"); 
    } else { 
        printf("Queue elements: "); 
        for (int i = front; i <= rear; i++) { 
            printf("%d ", queue[i]); 
        } 
        printf("\n"); 
    } 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
