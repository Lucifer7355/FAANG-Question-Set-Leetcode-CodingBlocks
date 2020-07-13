class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> sNums(nums.begin(), nums.end());
        return sNums.size() != nums.size();
    }
};
