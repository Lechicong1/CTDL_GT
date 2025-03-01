#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void reverse(int x) {
    stack<int> stack;
    string s=to_string(x);
    vector<char> output;
    if(s[0]=='-')
    output.push_back(s[0]);
    for(int i=0;i<s.length();i++){
       if(s[i]!='-')
      stack.push(s[i]);
    }
    while(!stack.empty()){
        output.push_back(stack.top());
        stack.pop();
    }
    // for(char x : output)
    // cout << x;

    for(int i=0;i<output.size();i++){
        if(i==0 && output[0]=='0'){
            continue;
        }
        cout<<output[i];
    }
}
int main(){
    int x ; 
    cout<<" nhap so can dao nguoc " ;
    cin>>x ;
    reverse(x);
}