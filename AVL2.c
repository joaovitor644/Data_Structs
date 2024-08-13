#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  uint32_t data;
  int8_t b;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct BinaryTree {
  Node *root;
} BinaryTree;


int8_t max(int8_t  a,int8_t b){
  return a > b? a : b;
}

int8_t hight(Node* node){
  if(node == NULL)
    return -1;
  int8_t left,right;
  right = hight(node->right);
  left = hight(node->left);
  return max(left + 1,right + 1);
}

int8_t balance(Node* node){
  int8_t left,right;
  left = hight(node->left);
  right = hight(node->right);
  return right - left;
}

Node *createNode(uint32_t data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->b = 0;
  return newNode;
}
void showInOrdem(Node *node) {
  if (node == NULL) {
    return;
  } else {
    if (node->left != NULL) {
      showInOrdem(node->left);
    }
    printf("%d - Balance:%d\n", node->data,node->b);
    if (node->right != NULL) {
      showInOrdem(node->right);
    }
  }
}
void showInOrdemDecresc(Node *node) {
  if (node == NULL) {
    return;
  } else {
  	if (node->right != NULL) {
      showInOrdemDecresc(node->right);
    }
    printf("%d - Balance:%d\n", node->data,node->b);
    if (node->left != NULL) {
      showInOrdemDecresc(node->left);
    }
  }
}

void rotacao_E(Node** raiz, BinaryTree* tree) {
    Node* eixo = (*raiz)->right;
    if(eixo->left == NULL){
      (*raiz)->right = NULL;
    }  else {
      (*raiz)->right = eixo->left;
    }
    eixo->left = (*raiz);
    eixo->b = balance(*raiz);
    eixo->left->b = balance(*raiz);
    if (*raiz == tree->root) {
        tree->root = eixo;
    }
    *raiz = eixo;
    (*raiz)->b = balance(*raiz);

}
void rotacao_D (Node** raiz,BinaryTree* tree) {
  Node* eixo = (*raiz)->left;
  if(eixo->right == NULL){
    (*raiz)->left = NULL;
  } else {
    (*raiz)->left = eixo->right;
  }
  eixo->right = (*raiz);
  eixo->b = balance(*raiz);
  eixo->right->b = balance(*raiz);
  if(*raiz == tree->root){
    tree->root = eixo;
  }
  *raiz = eixo;
  (*raiz)->b = balance(*raiz);
}


void insert(Node **dad, Node *node,BinaryTree* tree) {
  if (*dad == NULL) {
    *dad = node;
  } else {
    if ((*dad)->data <= node->data) {
      insert(&(*dad)->right, node,tree);
    } else {
      insert(&(*dad)->left, node,tree);
    }
  }
  (*dad)->b = balance(*dad);
  if((*dad)->b > 1 && (*dad)->left == NULL){
    rotacao_E(dad,tree);
  }
  if((*dad)->b < -1 && (*dad)->right == NULL){
    rotacao_D(dad,tree);
  }
  if((*dad)->b < -1 && (*dad)->left != NULL && (*dad)->left->b == 1){

    rotacao_E(&((*dad)->left), tree);
    rotacao_D(dad, tree);
  }
  if((*dad)->b > 1 && (*dad)->right != NULL && (*dad)->right->b == -1){
    rotacao_D(&((*dad)->right), tree);
    rotacao_E(dad, tree);

  }
  if((*dad)->b > 1 && (*dad)->right != NULL){
    rotacao_E(dad, tree);
  }
  if((*dad)->b < -1 && (*dad)->right != NULL){
    rotacao_D(dad,tree);
  }
}

  BinaryTree* createTree() {
    BinaryTree *newTree = (BinaryTree *)malloc(sizeof(BinaryTree));
    newTree->root = NULL;
    return newTree;
  }

  int main() {
    BinaryTree *tree = createTree();
    /*for (int i = 0; i < 10; i++) {
      insert(&tree->root, createNode(i + 1));
    }*/
    Node* n1 = createNode(1);
    Node* n2 = createNode(2);
    Node* n3 = createNode(3);
    Node* n4 = createNode(4);
    Node* n5 = createNode(5);
    Node* n6 = createNode(6);
    Node* n7 = createNode(7);
    Node* n8 = createNode(8);
    Node* n9 = createNode(9);
    Node* n10 = createNode(10);

    insert(&tree->root,n5,tree);
    //
    insert(&tree->root,n4,tree);
    //;
    //insert(&tree->root,n8,tree);

    //insert(&tree->root,n1,tree);
    insert(&tree->root,n2,tree);
    insert(&tree->root,n3,tree);
    insert(&tree->root,n6,tree);
    insert(&tree->root,n1,tree);
    insert(&tree->root,n7,tree);
    insert(&tree->root,n9,tree);
    insert(&tree->root,n10,tree);
    insert(&tree->root,createNode(11),tree);
    insert(&tree->root,createNode(12),tree);
    insert(&tree->root,createNode(13),tree);
    //rotacao_E(&n1,tree);
   // rotacao_D_E(tree->root,tree);
    //
    //insert(&tree->root,n8,tree);
    //
    //rotacao_D_E(&tree->root,tree);
    //rotacao_D(&n9,tree);

    ///*Remove(tree,7);
    printf("EPD:\n");
    showInOrdem(tree->root);



    return 0;
  }
