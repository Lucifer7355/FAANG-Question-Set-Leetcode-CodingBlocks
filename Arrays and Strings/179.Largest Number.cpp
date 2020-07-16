bool myCompare(int a,int b){
    return to_string(a) + to_string(b) > to_string(b)+to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),myCompare);
        if(nums[0]==0){
            return "0";
        }
        string ans;
        for(auto i : nums){
            ans.append(to_string(i));
        }
        return ans;
    }
};
