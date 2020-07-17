class Solution {
public:
    int searchFirst(vector<int>& nums,int target){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MAX;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]==target){
                ans = min(ans,mid);
                end = mid - 1;
            }else if(nums[mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }

    int searchSecond(vector<int>& nums,int target){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = INT_MIN;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]==target){
                ans = max(ans,mid);
                start = mid + 1;
            }else if(nums[mid]>target){
                end = mid - 1;
            }else{
                start = mid + 1; 
            }
        }
        return ans==INT_MIN ? -1 : ans;
    }

    vector<int> searchRange(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> result;
        int first = searchFirst(nums,target);
        int second = searchSecond(nums,target);
        result.push_back(first);
        result.push_back(second);
        return result;
    }
};
