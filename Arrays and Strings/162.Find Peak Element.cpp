class Solution {
public:
    int search(vector<int>& nums,int start,int end){
        if(start==end){
            return start;
        }
        int mid = start + (end - start)/2;
        if(nums[mid]<nums[mid+1]){
            return search(nums,mid+1,end);
        }
        return search(nums,start,mid);
    }

    int findPeakElement(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        return search(nums,start,end);
    }
};
