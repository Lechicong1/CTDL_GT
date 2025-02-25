#include<iostream>
using namespace std;
// tim phan tu nho nhat va vi tri cua no 
// danh gia do phuc tap 
int main(){
    int a[10]={12,2,3,4,1,6,7,8,9,10};
    int min=a[0];
    int index=0;
    for(int i=0;i<10;i++){     // O(n)
        if(a[i]<min){         // O(1)
            min=a[i];           //O1
            index=i;            //O(1)
        }
    }
    cout<<"min la " << min << "tai vi tri thu " << index << endl;

        // do phuc tap bai toan la : O(n)
} 