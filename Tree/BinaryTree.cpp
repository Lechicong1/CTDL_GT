#include<iostream>
using namespace std;
class NodeTree{
    public:
    int data;
    NodeTree *left;
    NodeTree *right;
    NodeTree(int value){
        data=value;
        left=right=NULL;
    }
};
class MybinaryTree{
    private:
    NodeTree* root;
    public : 
    MybinaryTree(){
        root=NULL;
    }
    NodeTree* getRoot(){
        return root;
    }
    void insert(int val){
        if(root==NULL){
            root= new NodeTree(val);
            return;
        }
        NodeTree* temp=root;
       while(true){
        
        if(val>temp->data){
            if(temp->right==NULL){
                temp->right=new NodeTree(val);
                break;
            }
            else{
                temp=temp->right;
            }
        
        }
        else{
            if(temp->left==NULL){
                temp->left=new NodeTree(val);
                break;
            }
            else{
                temp=temp->left;
            }
          
        }
       }


    }  
    void duyetbst(NodeTree* root){
        NodeTree* temp=root;
        if(temp==NULL){
            return;
        }
        duyetbst(temp->left);
        cout<<temp->data <<" " ; 
        duyetbst(temp->right);

    }
  bool findNode(NodeTree* root,int key){
            if (root == nullptr) {
                return false; // Không tìm thấy
            }
            if(key==root->data){
                return true;
            }
            if(key<root->data){
                return findNode(root->left,key);
            }
            return findNode(root->right,key);
          
        }
    NodeTree* deleteNode(NodeTree* root,int key){


        return root;
    }

};
int main(){
    MybinaryTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);
    bst.duyetbst(bst.getRoot());
    if(bst.findNode(bst.getRoot(),6))
    cout<<"find"<<endl;
    else
    cout<<"not find"<<endl;
    
}