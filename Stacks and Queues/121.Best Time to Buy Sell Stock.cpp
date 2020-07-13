class Solution {
public:
    int maxProfit(vector<int>& v){
        stack<int> s;
        int maxProfit = 0;
        int n = v.size();
        if(n==0){
            return 0;
        }
        s.push(v[0]);
        int i = 1;
        while(i<n){
            if(v[i]<s.top()){
                s.push(v[i]);
            }else{
                maxProfit = max(maxProfit,v[i]-s.top());
            }
            i++;
        }
        return maxProfit;
    }
};
