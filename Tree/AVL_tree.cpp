/* cay can bang , chieu cao cua cay con ben trai va cay con ben phai khong lech qua 1 
trong bst , truong hop xau nhat tim kiem co the mat O(n) nen can co AVL */
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    int height;
};
node *makeNode(int x ){
     node *newNode=new node();
     newNode->data=x;
     newNode->right=NULL;
     newNode->left=NULL;
     newNode->height=1;
     return newNode;
}
int height(node* node){
    if(node==NULL)  return 0;
    return node->height;
}
// tinh he so can bang 
int Balance(node *node){
    if(node==NULL) return 0; 
    return height(node->left)-height(node->right);
}
// xoay phai 
node *rotateRight(node* root){
      node* x=root->left;
      node *y=x->right;
      root->left=y;
      x->right=root;    
      root->height=max(height(root->left),height(root->right))+1;
      x->height=max(height(x->left),height(x->right))+1;
     return x;
}
node *rotateLeft(node *root){
     node *x=root->right;
     node *y=x->left;
     root->right=y;
     x->left=root;
     root->height=max(height(root->left),height(root->right))+1;
     x->height=max(height(x->left),height(x->right))+1;
     return x;
}
class AVLTrees{
    private: 
    node *root;
    public : 
    node* insert(node *roott,int key){
        if(roott==NULL){
            return makeNode(key);
        }
        if(key< root->data){
            root->left=insert(root->left,key);
        }
        else if(key >root->data){
            root->right=insert(root->right,key);
        }
        // cap nhat chieu cao cua cay moi khi them node moi  
        roott->height=1+max(height(roott->left),height(roott->right));
        // tinh he so can bang  
        int balance=Balance(roott);
        // cac truong hop mat can bang  
        //th1 : cay con trai lech trai 
        if(balance > 1 && key < roott->left->data){
            return rotateRight(roott); // quay phai
        }
        // th2 : cay con phai lech phai 
        if(balance<-1 && key>roott->right->data){
            return rotateLeft(roott);
        }
        // th3 : cay con trai lech phai ( left-right)
        if(balance >1 && key >root->left->data){
            roott->left=rotateLeft(roott->left);
            return rotateRight(roott);
        }
        // th4 : cay con phai lech trai ( right_left)
        if(balance <-1 && key <root->right->data){
            roott->right=rotateRight(roott);
            return rotateLeft(roott);
        }
        return roott;

    }



};
