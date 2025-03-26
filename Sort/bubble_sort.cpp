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
    int a[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>n;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<"mang sau khi sap xep " <<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

}