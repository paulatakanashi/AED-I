#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore binária de busca
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó com o dado especificado
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um elemento na árvore
Node* insert(Node* root, char data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Função de travessia em ordem (inorder traversal)
void inorderTraversal(Node* root, int* isFirst) {
    if (root != NULL) {
        inorderTraversal(root->left, isFirst);
        if (!(*isFirst)) {
            printf(" ");
        } else {
            *isFirst = 0;
        }
        printf("%c", root->data);
        inorderTraversal(root->right, isFirst);
    }
}

// Função de travessia em pré-ordem (preorder traversal)
void preorderTraversal(Node* root, int* isFirst) {
    if (root != NULL) {
        if (!(*isFirst)) {
            printf(" ");
        } else {
            *isFirst = 0;
        }
        printf("%c", root->data);
        preorderTraversal(root->left, isFirst);
        preorderTraversal(root->right, isFirst);
    }
}

// Função de travessia em pós-ordem (postorder traversal)
void postorderTraversal(Node* root, int* isFirst) {
    if (root != NULL) {
        postorderTraversal(root->left, isFirst);
        postorderTraversal(root->right, isFirst);
        if (!(*isFirst)) {
            printf(" ");
        } else {
            *isFirst = 0;
        }
        printf("%c", root->data);
    }
}

// Função para pesquisar um elemento na árvore
int search(Node* root, char data) {
    if (root == NULL) {
        return 0;
    } else {
        if (data == root->data) {
            return 1;
        } else if (data < root->data) {
            return search(root->left, data);
        } else {
            return search(root->right, data);
        }
    }
}

int main() {
    Node* root = NULL;

    char command[10];
    char data;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &data);
            root = insert(root, data);
        } else if (strcmp(command, "INFIXA") == 0) {
            int isFirst = 1;
            inorderTraversal(root, &isFirst);
            printf("\n");
        } else if (strcmp(command, "PREFIXA") == 0) {
            int isFirst = 1;
            preorderTraversal(root, &isFirst);
            printf("\n");
        } else if (strcmp(command, "POSFIXA") == 0) {
            int isFirst = 1;
            postorderTraversal(root, &isFirst);
            printf("\n");
        } else if (strcmp(command, "P") == 0) {
            scanf(" %c", &data);
            if (search(root, data)) {
                printf("%c existe\n", data);
            } else {
                printf("%c nao existe\n", data);
            }
        }
    }

    return 0;
}
