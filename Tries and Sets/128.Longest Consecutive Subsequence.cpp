class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> s,d;
        for(auto i : nums){
            s.insert(i);
        }
        int maxLength = 0;
        for(auto i : nums){
            int c = 0;
            int j = i;
            while(s.count(j) && !d.count(j)){
                c++;
                d.insert(j++);
            }
            j = i - 1;
            while(s.count(j) && !d.count(j)){
                c++;
                d.insert(j--);
            }
            maxLength = max(maxLength,c);
        }
        return maxLength;
    }
};
