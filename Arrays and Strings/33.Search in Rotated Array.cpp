class Solution {
public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while(start<=end){
            int mid  = end + (start-end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>nums[n-1]){
                if(target>nums[mid] || target<nums[0]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
            else{
                if(target<nums[mid] || target>nums[n-1]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};
