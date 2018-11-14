/* 국민대학교 컴퓨터공학부 20163170 최은주
   Binary Search Tree의 삽입, 삭제 알고리즘 */

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

typedef struct NodeStruct{
  int key;
  struct NodeStruct* left;
  struct NodeStruct* right;
}Node;

Node* getNode();
int height(Node* T);
int noNodes(Node* T);
Node* maxNode(Node* T);
Node* minNode(Node* T);
void insertBST(Node*& T, int newKey);
void deleteBST(Node*& T, int deleteKey);
void inorder(Node* T);
void searchParentBST(Node* T, int searchKey, Node*& Q, Node*& P);

void inorder(Node* T){
  if(T != NULL){
    inorder(T->left);
    cout << T->key << " ";
    inorder(T->right);
  }
}

Node* getNode(){
  Node* newNode = NULL;
  newNode = (Node*) malloc(sizeof(Node));
  return newNode;
}

void insertBST(Node*& T, int newKey){
  Node* P = T;
  Node* Q;
  while(P != NULL){
    if(newKey == P->key)  return;
    Q = P;
    if(newKey < P->key) P = P->left;
    else P = P->right;
  }
  Node* newNode = getNode();
  newNode->key = newKey;
  newNode->left = NULL;
  newNode->right = NULL;

  if(T == NULL) T = newNode;
  else if(newKey < Q->key) Q->left = newNode;
  else Q->right = newNode;
  return;
}

int height(Node* T){
  if(T == NULL) return 0;
  return max(height(T->left), height(T->right)) + 1;
}

int noNodes(Node* T){
  if(T == NULL) return 0;
  return noNodes(T->left) + noNodes(T->right) + 1;
}

Node* maxNode(Node* T){
  Node* R = T;
  while(R->right != NULL)
    R = R->right;
  return R;
}

Node* minNode(Node* T){
  Node* L = T;
  while(L->left != NULL)
    L = L->left;
  return L;
}

void searchParentBST(Node* T, int searchKey, Node*& Q, Node*& P){
  Q = NULL;
  P = T;
  while(P != NULL){
    if(searchKey == P->key) return;
    Q = P;
    if(searchKey < P->key) P = P->left;
    else P = P->right;
  }
  return;
}

void deleteBST(Node*& T, int deleteKey){
  Node* P = NULL;
  Node* Q = NULL;
  searchParentBST(T, deleteKey, Q, P);
  Node* R;

  if(P == NULL) return; //삭제할 원소가 없음

  if((P->left == NULL) && (P->right == NULL)){
    if(Q != NULL){
      if(Q->left == P)  Q->left = NULL;
      else Q->right = NULL;
    }
    else T = NULL;
  }//삭제할 노드의 차수가 0인 경우(리프 노드)

  else if((P->left == NULL) || (P->right == NULL)){
    if(Q!=NULL){
      if(P->left != NULL){
        if(Q->left == P) Q->left = P->left;
        else Q->right = P->left;
      }
      else{
        if(Q->left = P) Q->left = P->right;
        else Q->right = P->right;
      }
    }
    else{
      if(P->left != NULL) T = P->left;
      else                T = P->right;
    }
  }//삭제할 노드의 차수가 1인 경우

  else if((P->left != NULL) && (P->right != NULL)){
    int flag = 0;
    if(height(P->left) > height(P->right)){
      R = maxNode(P->left);
      flag = -1;
    }//높이 비교 -> 왼쪽 서브트리에서 교체
    else if(height(P->left) < height(P->right)){
      R = minNode(P->right);
      flag = 1;
    }//높이 비교 ->오른쪽 서브트리에서 교체
    else{
      if(noNodes(P->left) >= noNodes(P->right)){
        R = maxNode(P->left);
        flag = -1;
      }
      else{
        R = minNode(P->right);
        flag = 1;
      }
    }//노드의 수 비교

    P->key = R->key;
    if(flag == -1){
      deleteBST(P->left, R->key);
    }
    else if(flag == 1){
      deleteBST(P->right, R->key);
    }

  }//삭제할 노드의 차수가 2인 경우
}

int main(){
  Node* T = NULL;
  //삽입
  insertBST(T, 8);    inorder(T);     cout << endl;
  insertBST(T, 18);   inorder(T);     cout << endl;
  insertBST(T, 11);   inorder(T);     cout << endl;
  insertBST(T, 5);    inorder(T);     cout << endl;
  insertBST(T, 15);   inorder(T);     cout << endl;
  insertBST(T, 4);    inorder(T);     cout << endl;
  insertBST(T, 9);    inorder(T);     cout << endl;
  insertBST(T, 1);    inorder(T);     cout << endl;
  insertBST(T, 7);    inorder(T);     cout << endl;
  insertBST(T, 17);   inorder(T);     cout << endl;
  insertBST(T, 6);    inorder(T);     cout << endl;
  insertBST(T, 14);   inorder(T);     cout << endl;
  insertBST(T, 10);   inorder(T);     cout << endl;
  insertBST(T, 3);    inorder(T);     cout << endl;
  insertBST(T, 19);   inorder(T);     cout << endl;
  insertBST(T, 20);   inorder(T);     cout << endl;
  //삭제1 (삽입순서와 동일)
  deleteBST(T, 8);    inorder(T);     cout << endl;
  deleteBST(T, 18);   inorder(T);     cout << endl;
  deleteBST(T, 11);   inorder(T);     cout << endl;
  deleteBST(T, 5);    inorder(T);     cout << endl;
  deleteBST(T, 15);   inorder(T);     cout << endl;
  deleteBST(T, 4);    inorder(T);     cout << endl;
  deleteBST(T, 9);    inorder(T);     cout << endl;
  deleteBST(T, 1);    inorder(T);     cout << endl;
  deleteBST(T, 7);    inorder(T);     cout << endl;
  deleteBST(T, 17);   inorder(T);     cout << endl;
  deleteBST(T, 6);    inorder(T);     cout << endl;
  deleteBST(T, 14);   inorder(T);     cout << endl;
  deleteBST(T, 10);   inorder(T);     cout << endl;
  deleteBST(T, 3);    inorder(T);     cout << endl;
  deleteBST(T, 19);   inorder(T);     cout << endl;
  deleteBST(T, 20);   inorder(T);     cout << endl;
  //재삽입
  insertBST(T, 8);    inorder(T);     cout << endl;
  insertBST(T, 18);   inorder(T);     cout << endl;
  insertBST(T, 11);   inorder(T);     cout << endl;
  insertBST(T, 5);    inorder(T);     cout << endl;
  insertBST(T, 15);   inorder(T);     cout << endl;
  insertBST(T, 4);    inorder(T);     cout << endl;
  insertBST(T, 9);    inorder(T);     cout << endl;
  insertBST(T, 1);    inorder(T);     cout << endl;
  insertBST(T, 7);    inorder(T);     cout << endl;
  insertBST(T, 17);   inorder(T);     cout << endl;
  insertBST(T, 6);    inorder(T);     cout << endl;
  insertBST(T, 14);   inorder(T);     cout << endl;
  insertBST(T, 10);   inorder(T);     cout << endl;
  insertBST(T, 3);    inorder(T);     cout << endl;
  insertBST(T, 19);   inorder(T);     cout << endl;
  insertBST(T, 20);   inorder(T);     cout << endl;
  //삭제2 (삽입순서의 역순)
  deleteBST(T, 20);   inorder(T);     cout << endl;
  deleteBST(T, 19);   inorder(T);     cout << endl;
  deleteBST(T, 3);    inorder(T);     cout << endl;
  deleteBST(T, 10);   inorder(T);     cout << endl;
  deleteBST(T, 14);   inorder(T);     cout << endl;
  deleteBST(T, 6);    inorder(T);     cout << endl;
  deleteBST(T, 17);   inorder(T);     cout << endl;
  deleteBST(T, 7);    inorder(T);     cout << endl;
  deleteBST(T, 1);    inorder(T);     cout << endl;
  deleteBST(T, 9);    inorder(T);     cout << endl;
  deleteBST(T, 4);    inorder(T);     cout << endl;
  deleteBST(T, 15);   inorder(T);     cout << endl;
  deleteBST(T, 5);    inorder(T);     cout << endl;
  deleteBST(T, 11);   inorder(T);     cout << endl;
  deleteBST(T, 18);   inorder(T);     cout << endl;
  deleteBST(T, 8);    inorder(T);     cout << endl;

  return 0;

}
