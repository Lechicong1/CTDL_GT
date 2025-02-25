#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
  stack<int> myStack;
  int n=10;
  int temp=0;
  while(n!=0){
    temp=n%2;
    myStack.push(temp);
    n=n/2;
  }
  vector<int> output; 
  while(!myStack.empty()){
   output.push_back(myStack.top());
   myStack.pop();

  }
  for(int x : output ){
    cout<<x;
  }


}

