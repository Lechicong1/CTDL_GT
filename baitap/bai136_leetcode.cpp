#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    map<int,int> map;
       for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
       } 
       for(auto x : map){
         if(x.second==1){
            return x.first;
         }
       }
       return -1;
}
int main(){
    vector<int> v ={4,1,2,1,2};
    int sig= singleNumber(v);
    cout<<" so xuat hien 1 lan la : " << sig ;
}