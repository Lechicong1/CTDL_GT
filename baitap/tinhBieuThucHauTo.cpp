#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
bool checktoantu(char c){
    if(c=='+' || c=='-'|| c=='*'|| c=='/' || c=='^')
    return true;
    return false;
}
bool checktoanhang(char c){
    return isalnum(c);
}
int tinhtoan(int a ,int b,char c){
    int kq;
    switch(c){
        case '+' :
            return kq= a+b;
            break;
        case '-' :
            return kq=a-b;
            break;
        case '*': 
            return kq=a*b;
            break;
        case '/': 
            if(b==0)
            cout<<"khong the chia";
            else
            return kq= a/b;
            break;

    }
    return kq;
}
int doisangso(char c){
    if(c=='A')
     return 5;
     else if(c=='B')
     return 7;
     else if(c=='C')
     return 3;
     else if(c=='D')
     return 2;
     else if(c=='F')
     return 5;
     else if(c=='E')
     return 1;
    return -1;
}
int main(){
    stack<int> mystack;
    string s="ABC-/DEF+*+";
    for(int i=0;i<s.length();i++){
        if(checktoantu(s[i])){
            char c1,c2;
            c1=mystack.top(); 
            mystack.pop();
            c2=mystack.top();
            mystack.pop();
            int a=doisangso(c1);
            int b=doisangso(c2);
            int kq = tinhtoan(b,a,s[i]);
            mystack.push(kq);
        }
        if(checktoanhang(s[i])){
            mystack.push(s[i]);
        }
    }
    int kq=mystack.top();
    cout<<kq;
}