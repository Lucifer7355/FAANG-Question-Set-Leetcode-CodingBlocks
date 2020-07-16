class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int> m;
        for(auto i : candies){
            m[i] = true;
        }
        return min(m.size(),candies.size()/2);
    }
};
