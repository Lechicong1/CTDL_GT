#include<bits/stdc++.h>
using namespace std;
struct node{
        int data;
        node *next;
};
node *makeNode(int x){
    node *newNode=new node();
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
class MyQueue{
    private : 
    node *topNode=NULL;
    int n=0;
    public : 
    int size(){
        return n;
    }
    bool isEmpty(){
        if(topNode==NULL){
            return true;
        }
        return false;
    }
    void enQueue(int x){
        node *newNode=makeNode(x);
        if(topNode==NULL){
           topNode=newNode;
           return;
        }
        
        newNode->next=topNode;
        topNode=newNode;
    }
    void deQueue(){
        if(topNode==NULL)
        return; 
        node *temp=topNode;
        if(topNode->next==NULL){
            topNode=NULL;
            delete temp;
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node *last=temp->next;
        temp->next=NULL;
        delete last;
    }
    void peek(){        // peek la thang duoc them vao dau tien 
        node *peek=topNode;
        while(peek->next!=NULL){
            peek=peek->next;
        }
        cout<<"peek : " << peek->data << endl;
        delete peek;
    }
    void show(){
        node *temp=topNode;
        while(temp!=NULL){
            cout<<temp->data << "->" ;
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    MyQueue Queue;
    Queue.enQueue(1);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.show();
    Queue.deQueue();
    Queue.show();
    Queue.peek();
}
