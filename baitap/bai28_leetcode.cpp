#include<iostream>
#include<queue>
using namespace std;
int strStr(string haystack, string needle) {
    int index = -1;
    int temp=0;
        queue<char> q;
        for(int i=0;i<needle.length();i++){
            q.push(needle[i]);
        }
        for(int j=0;j<haystack.length();j++){
            if(haystack[j]==q.front()){
                    if(temp==0){
                        index=j;
                    }
                    temp=1;
                    q.pop();
            }
            else
             break;
        }
        if(q.empty()==false){
            index=-1;
        }
      
        return index;

}   
int main(){
     string haystackd="leetcode";
     string needle="leeto";
     int out=strStr(haystackd,needle);
     cout<<out;
}