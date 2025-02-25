#include<iostream>
#include<algorithm>
using namespace std;
// so sanh phan tu voi cac phan tu dung truoc , tim ra vi tri thich hop va chen vao 


int main(){
    int a[3]={3,4,1}; 
    for(int i=1;i<3;i++){      // i=2
       int x=a[i];         //x=1
       int index =i-1;     //index=1;
      while(x<a[index] && index>=0){    // 1<4       1<a[0]=3 
         a[index+1]=a[index];        //a[2]=4->3 4 4    a[1]=3->3 3 4
         index --;                  // index =0;       // index=-1
      }
        a[index+1]=x;               // a[0]=1; ->1 3 4

       }
    cout<<"mang sau khi sap xep " <<endl;
    for(int i=0;i<3;i++){
        cout<<a[i]<<" ";
    }

}