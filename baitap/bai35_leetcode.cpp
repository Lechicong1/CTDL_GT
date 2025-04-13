#include<iostream>
#include<vector>
using namespace std;
int binarySearch(int a[],int l ,int r,int x){
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x) return m;
        if(a[m]<x){
            return binarySearch(a,l,m-1,x);

        }
        if(a[m]>x){
            return binarySearch(a,m+1,r,x);
        }
    }
    return -1;
}
int searchInsert(int a[],int n, int target) {
    int kq=binarySearch(a,0,n-1,target);
    int i=0;
       if(kq!=-1){
            return kq;
       }
       else{
        while(a[i]<target) 
        i++;
       }
       return i;

}
int main(){
    int a[4]={1,3,5,6};
   int kq= searchInsert(a,4,5);
    cout<<" kq : " << kq;
}