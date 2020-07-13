class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for(int i=0;i<n;i++){
            prefixSum.push_back(prefixSum[i] + nums[i]);
        }
        int ans = 0;
        for(auto i : prefixSum){
            int x = i - k;
            if(m.find(x)!=m.end()){
                ans = ans + m[x];
            }
            m[i]++;
        }
        return ans;        
    }
};
