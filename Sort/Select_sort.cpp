#include<iostream>
#include<algorithm>
using namespace std;
//tim min trong mang va dua ve dau mang 
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main(){
    int a[5]={4,3,2,9,6};
    for(int i=0;i<4;i++){
        int min=i;
    // tim vi tri min trong mang 
    for(int j=i+1;j<5;j++){                 
       if(a[min]>a[j]){       
         min=j;                           
       }     
    }
    if(min!=i){
        swap(a[min],a[i]);
    }
    }
    cout<<"mang sau khi sap xep " <<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    
}