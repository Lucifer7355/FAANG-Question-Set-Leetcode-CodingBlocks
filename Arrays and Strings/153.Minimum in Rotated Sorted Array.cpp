class Solution {
public:
    int findMin(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        if(nums[0]<=nums[n-1]){
            return nums[0];
        }
        while(start<=end){
            int mid = (end + start)/2;     
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(nums[n-1]<nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
};
