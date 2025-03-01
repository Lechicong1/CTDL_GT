#include<iostream>
using namespace std;
//doc so nguyen tu ban phim cho toi khi gap so 0 , in ra cac phan tu am trong danh sach , neu k co in ra not found
int main(){
    int a[1000];
    int i=0;
    int size=0;
    int x; 
    while(true){
        cin>>x; 
        a[i]=x;
        i++;
        size++;
        if(x==0){
            break;
        }
    }
    int find=0;
    for(int j=0;j<size;j++){
            if(a[j]<0){
                cout<<a[j]<<" " ;
                find=1;
            }
    }
    if(find==0){
        cout<<"NOT FOUND";
    }
}