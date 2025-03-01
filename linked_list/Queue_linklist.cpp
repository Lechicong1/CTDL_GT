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
    node *front;
    node *rear;
    int size;
    int numberItem;
    public : 
    MyQueue(int size){
    front=rear=NULL;
    this->size=size;
    numberItem=0;
   }
    bool isEmpty(){
        if(numberItem==0){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(numberItem==size){
            return true; 
        }
        return false;
    } 
    // them phan tu vao cuoi danh sach lien ket 
    void enQueue(int x){
        if(isFull()){
            return;
        }
        node *newNode=makeNode(x); // tao node moi 
        if(front==NULL){
           rear=newNode;
           front=newNode;
          
        }
        else{
           rear->next=newNode;  // noi node cuoi cung voi node moi them vao
            rear=newNode;       // cho con tro rear tro den node cuoi 
           
        }
        numberItem++;
     
    }
    // xoa phan tu o dau dslk 
    bool deQueue(){
        if(isEmpty()){
            return false;
        }
        node *temp=front;
        if(numberItem==1){
             front=NULL;
        }
        else{
            front=front->next;    // cho front tro vao node thu 2 

        }
        numberItem--;
        delete temp;

        
    }
    void peek(){        // peek la thang duoc them vao dau tien 
       cout<<front->data;
    }
    void show(){
        node *temp=front;
        while(temp!=NULL){
            cout<<temp->data << "->" ;
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        delete temp;
    }
};
int main(){
    MyQueue Queue(10);
    Queue.enQueue(1);
    Queue.enQueue(2);
    Queue.enQueue(3);
    Queue.show();
    Queue.deQueue();
    Queue.show();
    Queue.peek();
}
