#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m,n ;
    cout<<" nhap tong so con " ; 
    cin>>m;
    cout<<"nhap tong so chan "; 
    cin>>n; 
    int soga,socho;  
    soga=(4*m-n)/2;   
    socho= m-soga;
    cout<<soga << " " << socho;

}
void quicksort(int a[],int l ,int r){
    int x=a[(l+r)/2];
    int i=l;
    int j=r;
    do{
        while(x<a[i]) i++;
        while(x>a[j]) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while(i<=j);
    if(l<j) 
    quicksort(a,l,j);
    if(i<r)
    quicksort(a,i,r);
}