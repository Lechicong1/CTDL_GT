#include<iostream>
#include<stack>
#include<cstdlib>
#include<iomanip>
using namespace std;
bool checktoantu(char c){
    if(c=='+' || c=='-'|| c=='*'|| c=='/' || c=='^')
    return true;
    return false;
}
bool checktoanhang(char c){
    return isalnum(c);
}
float tinhtoan(float a ,float b,char c){
    float kq;
    switch(c){
        case '+' :
            kq= a+b;
            break;
        case '-' :
         kq=a-b;
            break;
        case '*': 
      kq=a*b;
            break;
        case '/': 
            if(b==0)
            cout<<"khong the chia";
            else
            kq= float(a)/b;
            break;

    }
  return kq;
}
float doisangso(char c){
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
     return 0; 

}
int main(){
    stack<float> mystack;
    string s="(3*x+2)^2*(2*x^2-x+5)+10";
    for(int i=0;i<s.length();i++){
        if(checktoantu(s[i])){
            char c1,c2;
            float a=mystack.top(); 
            mystack.pop();
            float b=mystack.top();
            mystack.pop();
            float kq = tinhtoan(b,a,s[i]);
            mystack.push(kq);
        }
        if(checktoanhang(s[i])){
            mystack.push(doisangso(s[i]));
        }
    }
    float kq=mystack.top();
 
    cout<<kq;
}   