#include<iostream>
using namespace std;
void insert(int a[] ,int n,int k,int x){
    for(int i=n;i>k;i--){
        a[i]=a[i-1];
    }
    a[k]=x;
}
int main(){
    int a[10]={1,2,3,4,5};
    insert(a,5,2,9);
    for(int x : a){
        cout<<x ;
    }
}