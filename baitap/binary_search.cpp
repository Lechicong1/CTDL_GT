#include<iostream>
#include<algorithm>
using namespace std;
int binary_search(int a[], int start,int end ,int x ) { 
    // sort(a,a+n);
   int  m=(start+end)/2;
   if(start>end){
    return -1;
   }
    if(a[m]==x)                                                                              
    return 1; 
    else if (a[m]<x){
        return binary_search(a,m+1,end,x);
    
    }
    return binary_search(a,start,m-1,x);

}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
   
    int kq= binary_search(a,0,9,1);
    if(kq==1){
        cout<<" find " ;

    }
    else 
      cout<<" not found";
}