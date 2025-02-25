#include<iostream>
#include<algorithm>
using namespace std;
// so sanh 2 phan tu va swap
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main(){
    int a[5]={4,3,2,9,6}; 
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    cout<<"mang sau khi sap xep " <<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

}