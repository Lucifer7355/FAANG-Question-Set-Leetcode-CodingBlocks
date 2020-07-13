class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0;
        int j = 0;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(m.count(ch)){
                j = max(m[ch]+1,j);
            }
            ans = max(ans,i-j+1);
            m[ch] = i;
        }
        return ans;
    }
};
