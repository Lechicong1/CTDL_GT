#include<iostream>
using namespace std;
int main(){
    int a[5]={1,4,7,5,9};
    int max=a[0];
    int second=0;
    for(int i=0;i<5;i++){
        if(max<a[i]){
            second=max;
            max=a[i];
        }
    }
    cout<<"so lon thu hai trong mang la " <<second << endl;
}