#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
void doinhiphan(int x){
    stack<int>s;
    while(x!=0){
        int phandu=x%2;
        s.push(phandu);
        x=x/2;
        }
    while(s.empty()==false){
        cout<<s.top();
        s.pop();
    }
}
int doithapPhan(string x){
    int kq=0; // 1010
    int  j=0;
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]=='1'){
         kq=kq+(int)pow(2,j);
        }
        j++;
        
    }
    return kq;
}
void  addBinary(string a, string b) {
    int x=doithapPhan(a);
    int y=doithapPhan(b);
    int tong=x+y;
    doinhiphan(tong);
}
int main(){
    addBinary("1010","1011");
}