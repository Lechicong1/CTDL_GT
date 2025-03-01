#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>> kq;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                for(int k=0;k<nums.size();k++){
                    if(i!=j && i!=k && j!=k && nums[i]+nums[j]+nums[k]==0){
                        kq.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        return kq;
}
int main(){
    vector<int> input;
    input.push_back(-1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    input.push_back(-1);
    input.push_back(-4);
   vector<vector<int> > output =threeSum(input);
   for(int i=0;i<output.size();i++){
            for(int j=0;j<output[i].size();j++){
                    cout<< output[i][j];
            }
            cout<< " ;";
   }

}