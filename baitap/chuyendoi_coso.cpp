#include<iostream>
#include<stack>
using namespace std;
// chuyen tu thap phan sang nhi phan
// chia lay du cho 2 , phan du day vao stack 
// lay nguoc tu stack ra ->kq
int main(){
  stack<int> myStack;
  int n=10;
  int temp=0;
  while(n!=0){
    temp=n%2;
    myStack.push(temp);
    n=n/2;
  }
  while(!myStack.empty()){
   cout<< myStack.top();
   myStack.pop();

  }
  
}

