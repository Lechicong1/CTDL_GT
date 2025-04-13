#include<bits/stdc++.h>
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
    void reverseList(){
        Node *temp=head;
        while(temp->next!=NULL){
            Node *behind=temp->next;
            temp->next=behind->next;
            behind->next=head;
            head=behind;
        }
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
    LinkList l ;
    l.InsertLast(1);
    l.InsertLast(2);
    l.InsertLast(3);
    l.InsertLast(4);
    l.InsertLast(5);
    l.reverseList();
    l.duyet();
}