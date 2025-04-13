#include<iostream>
using namespace std;
 struct node{
    int data;
    node *next;
};
node *makeNode(int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
class LinkList{
    private : 
    node *head;
    public : 
    LinkList(){
        head=NULL;
    }
    void add(int x){    
        node *newNode=makeNode(x);
        if(head==NULL){
            head=newNode;
            return;
        }
        // if(head->next==NULL){
        //     head->next=newNode;
        // }
        // tim node cuoi 
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;

    }
    void deleteDuplicates() {
        node *temp=head;
        while(temp!=NULL){
            node *behind=temp->next;    
            if(temp->data==behind->data){
                temp->next=behind->next;
                delete behind;
            }
             temp=temp->next;       
        }
    }
    void duyet(){
        node *temp=head;
        while(temp!=NULL){
            cout<<temp->data <<",";
            temp=temp->next;
        }
        delete temp;
    }
};
int main(){
    LinkList l;
    l.add(1);
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(3);
    l.deleteDuplicates();
    l.duyet();
}