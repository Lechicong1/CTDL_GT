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
    NodeTree* insert(NodeTree *roott,int val){
        if(roott==NULL){
            return new NodeTree(val);
        }
        if(val < roott->data){
          roott->left= insert(roott->left,val);
        }
        else{
            roott->right= insert(roott->right,val);
        }
        return roott;                                      
    }

    //    while(true){
        
    //     if(val>temp->data){
    //         if(temp->right==NULL){
    //             temp->right=new NodeTree(val);
    //             break;
    //         }
    //         else{
    //             temp=temp->right;
    //         }
        
    //     }
    //     else{
    //         if(temp->left==NULL){
    //             temp->left=new NodeTree(val);
    //             break;
    //         }
    //         else{
    //             temp=temp->left;
    //         }
          
    //     }
    //    }
    void insert(int value){
        root=insert(this->root,value);
    }  
    // duyet theo thu tu truoc 
    void preOrder(NodeTree* roott){
        // tham goc truoc , sau do tham ben trai va tham ben phai 
        NodeTree *temp=roott;
        if(temp==NULL)
            return;
        cout<<temp->data<< " " ;
        preOrder(temp->left);
        preOrder(temp->right);    

    }
     // duyet theo thu tu giua
    void inOrder(NodeTree* roott){
        // thu tu : trai - giua-phai
        NodeTree *temp=roott;
        if(temp==NULL)
            return;
        inOrder(temp->left);
        cout<<temp->data << " ";
        inOrder(temp->right);

    }
    // duyet theo thu tu sau 
    void postOrder(NodeTree* roott){
        //thu tu : trai-phai-goc 
        NodeTree *temp=roott;
        if(temp==NULL)
            return;
        postOrder(roott->left);
        postOrder(roott->right);
        cout<<temp->data << " ";
        
    }
  bool searchBst(NodeTree* root,int key){
            if (root == nullptr) {
                return false; // Không tìm thấy
            }
            if(key==root->data){
                return true;
            }
            if(key<root->data){
                return searchBst(root->left,key);
            }
            return searchBst(root->right,key);
          
        }
    NodeTree* NodeMinMostLeft(NodeTree *roott){
        NodeTree* temp=roott;
        if(temp->left==NULL)
         return temp;
        return NodeMinMostLeft(temp->left);  
    }
    NodeTree* deleteNode(NodeTree* roott,int key){
        if(roott==NULL)    // truong hop cay rong
            return NULL;
        if(key<roott->data){
            roott->left=deleteNode(roott->left,key);    // tim node ben trai 
        }
        else if(key>root->data){                          // tim node ben phai 
            roott->right=deleteNode(roott->right,key);
        }
        else{
            // tim thay node can xoa 
            //th1 : node co 1 con hoac khong co con 
            if(roott->left==NULL){
                NodeTree* temp=roott->right;
                delete roott;
                return temp;
            }
            else if(roott->right==NULL){
                NodeTree *temp2=root->left;
                delete roott;
                return temp2;
            }
            else{
                //th2 : node co 2 con 
                //b1: tim node nho nhat ben nhanh phai (chon nhanh phai va duyet den node trai cung ben trai)
                NodeTree *temp=NodeMinMostLeft(root->right);
                root->data=temp->data ; // the node can xoa bang node vua tim duoc 
                // xoa node temp di 
                roott->right=deleteNode(roott->right,temp->data);
            }
            
        }
        // return ve node hien tai 
        return root;
    }
    void deleteNode(int val){
        root=deleteNode(this->root,val);
    }
    // tim chieu cao max cua cay 
    int maxDepth(NodeTree* root){
        if(root==NULL)
            return 0;
        int hLeft=maxDepth(root->left);
        int hRight=maxDepth(root->right);
       return ((hLeft>hRight)?hLeft:hRight) +1;

    }

};
int main(){
    MybinaryTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(4);
    bst.insert(6);
    bst.insert(9);                                                                                                                                                                                                                                                                                                                                                                                 
    bst.inOrder(bst.getRoot());
    cout<< bst.maxDepth(bst.getRoot());
    
}   