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
    int start=0; 
    while(start<5){  
    int min=a[start];  
    int index=start;     
    for(int i=start;i<5;i++){                 
       if(min>a[i]){       
         min=a[i];              
         index=i;               
       }    
           
    }
    swap(a[start],a[index]);    
    start++;                   

    }
    cout<<"mang sau khi sap xep " <<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    
}