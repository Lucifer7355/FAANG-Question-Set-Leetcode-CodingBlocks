class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){
        int n = T.size();
        vector<int> result(n,0);
        stack<int> s;
        s.push(0);
        for(int i=0;i<n;i++){
            while(!s.empty() && T[i]>T[s.top()]){
                int x = s.top();
                s.pop();
                result[x] = i - x;
            }
            s.push(i);
        }
        return result;
    }
};
