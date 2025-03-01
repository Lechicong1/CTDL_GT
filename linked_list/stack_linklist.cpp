#include<iostream>
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
class Mystack{
    private: 
    node *topNode;
    int max;
    int numberItem;
    public : 
    Mystack(int size){
        topNode=NULL;
        max=size;
        numberItem=0;
    }
    bool isEmpty(){
        if(numberItem==0){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(numberItem==max){
            return true;
        }
        return false;
    } 
    // them vao dau dslk
    void push(int x){
       
        if(isFull())
         return;
         node *newNode=makeNode(x);
        if(isEmpty()){
            topNode=newNode;
        }
        else{
            newNode->next=topNode;
            topNode=newNode;
        }
        numberItem++;
    }
    int size(){
        return numberItem;
    }
    // xoa node khoi cuoi dslk 
    void pop(){
        if(isEmpty()){
            return;
        }
        node *temp=topNode;
        // neu chi co 1 node dau 
        if(topNode->next==NULL){
            topNode=NULL;
            
        }
        else{
            topNode=topNode->next;
            
        }
        delete temp;
        numberItem--;
       
    }
    void duyet(){
        node *temp=topNode;
        while(temp!=NULL){
            cout<<temp->data <<"->";
            temp=temp->next;
        }
        cout<<"NULL" <<endl;
        delete temp;
    }
   
};
int main(){
    Mystack stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.duyet();
    stack.pop();
    stack.duyet();
    cout<<stack.size();
}