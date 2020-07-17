#include<bits/stdc++.h>
using namespace std;
 
int nc2(int x){
   return x*(x-1)/2;
}
 
int zeroSum(vector<int>& nums){
   int n = nums.size();
   unordered_map<int,int> m;
   vector<int> prefixSum;
   prefixSum.push_back(0);
   for(int i=0;i<n;i++){
       prefixSum.push_back(prefixSum[i] + nums[i]);
   }
   for(auto i : prefixSum){
       m[i]++;
   }
   int ans = 0;
   for(auto i : m){
       ans = ans + nc2(i.second);
   }
   return ans;
}
 
int main(){
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       vector<int> nums;
       for(int i=0;i<n;i++){
           int x;
           cin>>x;
           nums.push_back(x);
       }
       cout<<zeroSum(nums)<<endl;
   }
   return 0;
}

