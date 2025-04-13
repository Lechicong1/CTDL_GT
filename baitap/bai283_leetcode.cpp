#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int i=nums.front();
    int j= nums.back();

    while(i<=nums.size()){
        if(nums[i]==0){
            swap(nums[i],nums[j+1]);  
        }
        i++;
        j++;

    }    
}
int main(){
    vector<int> v={0,1,0,3,12};
    moveZeroes(v);
    for(int x: v){
        cout<<x << " " ; 
    }
}