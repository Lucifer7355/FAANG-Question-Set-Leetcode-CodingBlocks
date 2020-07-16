class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cs = nums[0];
        int ms = nums[0];
        for(int i=1;i<n;i++){
            if(cs<0){
                cs = 0;
            }
            cs = cs + nums[i];
            ms = max(ms,cs);
        }
        return ms;
    }
};
