#include<iostream>
#include<algorithm>
using namespace std;
bool binary_search(int a[],int n,int l,int x ) { 
    // sort(a,a+n);
    l=0;
   int  r=n-1;
   int   m=(l+r)/2;
    if(a[m]==x)
    return true; 
    else if (a[m]<x){
        return binary_search(a,n/2,l,x);
    
    }
    return binary_search(a,n/2,m+1,x);

}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
   
    bool kq= binary_search(a,10,0,4);
    if(kq){
        cout<<" find " ;

    }
    else 
      cout<<" not found";
}