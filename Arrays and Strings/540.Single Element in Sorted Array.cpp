class Solution {
public:

    bool single(vector<int>& nums,int mid){
        if(mid==0 && nums[mid]!=nums[mid+1]) return true;
        if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]) return true;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return true;
        return false;
    }

    int singleNonDuplicate(vector<int>& nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int start = 0;
        int end = n-1;
        int mid;
        while(start<=end){
            mid = end + (start-end)/2;

            if(single(nums,mid)){
                return nums[mid];
            }

            if(mid<n-1 && nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }

            if(mid>0 && nums[mid]==nums[mid-1]){
                if(mid%2==1){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return mid;
    }
};
