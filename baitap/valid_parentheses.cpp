#include<iostream>
#include<stack>
using namespace std;
/* cho chuoi dau vao , kiem tra xem co hop le hay khong 
intput : { } []
output : true
intput : { ] 
output : false
*/
bool isValid(string s) {
      stack<char> stack;
      for(int i=0;i<s.length();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                stack.push(s[i]);
            }
            else{
                char top=stack.top();
                if((s[i]=='}' && top=='{') || 
                    (s[i]==']' && top=='[') ||
                   (s[i]==')' && top=='(')){
                        stack.pop();
                    }
                    else
                    return false;
            }
      }
      return stack.empty()?true:false;

}
int main(){
    string s="{}[]";
    if(isValid(s)){
        cout<<"true";
    }
    else
     cout<<"false";
}