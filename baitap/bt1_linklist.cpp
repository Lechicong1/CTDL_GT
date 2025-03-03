//xay dung giai thuat bo sung 1 node vao dslk , minh hoa 1 dslk co 6 node 
// va them vao sau node thu tu 
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* makeNode(int data){
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
class LinkList{
    private : 
    Node *head;
    public : 
    LinkList(){
        head=NULL;
    }
    void InsertLast(int data){
        Node* newNode=makeNode(data); // tao Node moi 
        if(head==NULL){
            head=newNode;     // cho head tro den node moi 
        }
        else{
            Node *temp=head;
              // tim den node cuoi cung
            while(temp->next!=NULL){    
                temp=temp->next;
            }
            temp->next=newNode;
        }
    

    }
    void insertAfterFourth(int key,int index){
        Node* newNode=makeNode(key); // tao Node moi
        Node *temp=this->head;
        // duyet den node thu index 
        for(int i=1;i<index && temp!=NULL;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void duyet(){
        Node *temp=this->head;
        while(temp!=NULL){
            cout<<temp->data << "->" ;
            temp=temp->next;
        }
        cout<<"NULL" << endl;
    }
    
};
int main(){
    LinkList l;
    l.InsertLast(1);
    l.InsertLast(2);
    l.InsertLast(3);
    l.InsertLast(4);
    l.InsertLast(5);
    l.InsertLast(6);
    l.duyet();
    l.insertAfterFourth(9,4);
    l.duyet();
    

}