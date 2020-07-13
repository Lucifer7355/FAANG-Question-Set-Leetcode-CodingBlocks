class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        map<int,list<int>,greater<int>> p;
        for(auto i : s){
            p[m[i]].push_back(i);
        }
        
        for(auto i : p){
            for(auto j : i.second){
                if(result.size()<k){
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
