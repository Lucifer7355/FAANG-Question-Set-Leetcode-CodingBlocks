class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> result;
        for(auto s : strs){
            string x = s;
            sort(s.begin(),s.end());
            m[s].push_back(x);
        }
        
        for(auto i : m){
            vector<string> ans;
            for(auto j : i.second){
                ans.push_back(j);
            }
            result.push_back(ans);
        }
        
        return result;
    }
};
