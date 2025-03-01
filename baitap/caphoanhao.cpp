#include<iostream>
using namespace std;
// tim cap 2 so lien ke nhau co tong lon nhat  , bao gom ca pha tu dau mang va cuoi mang tao thanh vong tron 
int main(){
    int a[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int max=a[0]+a[n-1];
    int so1=a[0],so2=a[n-1];
    for(int i=0;i<n-1;i++){
       if(a[i]+a[i+1]>max){
          max=a[i]+a[i+1];
          so1=a[i];
          so2=a[i+1];
       }
    }
   if(max==a[0]+a[n-1]){
    cout << so2 << " " << so1 << endl;
   }
   else {
    cout << so1 << " " << so2 << endl;
   }
   
}