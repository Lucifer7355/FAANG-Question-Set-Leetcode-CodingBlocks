#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums){
        map<int,list<int>> m;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_front(nums[i][j]);
            }
        }
        
        for(auto i : m){
            for(auto j : i.second){
                result.push_back(j);
            }
        }
        
        return result;
    }
};
