#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n� da �rvore
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Fun��o para criar um novo n� da �rvore
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fun��o para inserir um elemento em uma �rvore bin�ria
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

// Fun��o para buscar um elemento em uma �rvore bin�ria
struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Fun��o para imprimir a �rvore em ordem (in-order)
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Fun��o para liberar a mem�ria ocupada pela �rvore
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;
    struct TreeNode* result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Imprimir arvore em ordem\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result == NULL) {
                    printf("Elemento nao encontrado!\n");
                } else {
                    printf("Elemento encontrado na arvore!\n");
                }
                break;
            case 3:
                printf("Arvore em ordem: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                freeTree(root);
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
