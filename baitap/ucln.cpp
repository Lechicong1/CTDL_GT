#include<iostream>
using namespace std;

int uc(int a,int b){
    if(b==0)
    return a ;
    return(b,a%b);
}
int main(){
    int a=6;
    int b=9;
    int ucln=uc(a,b);
    cout<<"ucln la : " << ucln;
}