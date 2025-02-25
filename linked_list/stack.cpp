#include<iostream>
using namespace std;
class MyStack{
    private : 
    int a[100];
    int n=0;
    int top=-1;
    public : 
    void push(int x ){
        a[n]=x;
        n++;
        
    }
    void pop(){
            if(n>=1){       // trong mang tinh thuc chat day khong phai xoa phan tu trong mang
                n--;        // ma chi thay thay doi giam chi so duyet xuong 
            }               // vi mang tinh cap phat bo nho khi chuong trinh chay va giai phong khi
                            // chtrinh ket thuc nen k the giai phong bo nho rieng le 
    }
    int top(){
        return a[n-1];
    }
    bool isFull(){
        if(top==n-1)
        return true;
        return false;
    }
    bool isEmpty(){
        if(n==0){
            return true;
        }
    }
    int size(){
        return n;
    }
    void duyet(){
        for(int i=0;i<n;i++){
            cout<<a[i] << " " ;
        }
        cout<< endl;
    }
};
int main(){
    MyStack stack ;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.duyet();
    stack.pop();
    stack.duyet();
}