#include<iostream>
using namespace std;
//vao truoc ra truoc 
class MyQueue{
    private :
    int a[100];
    int n=0; // size cau queue 
    public : 
    int size(){
        return n ;
    }
    void enqueue(int x){
        a[n]=x;
        n++;
    }
    void dequeue(){
        for(int i=0;i<n-1;i++){
            a[i]=a[i+1] ; // dich cac phan tu sang trai 
        }
        n--;     //giam size cua queue di 1 don vi
    }
    int peek(){
        return a[0];
    }
    bool isEmpty(){
        if(n==0)
        return true;
    }
    void duyet(){
        for(int i=0;i<n;i++){
            cout<<a[i] <<  " ";
        }
        cout<<endl;
    }
};
int main(){
    MyQueue queue ; 
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.duyet();
   cout<<  queue.peek()<< endl;
   queue.dequeue(); 
   queue.duyet();

}