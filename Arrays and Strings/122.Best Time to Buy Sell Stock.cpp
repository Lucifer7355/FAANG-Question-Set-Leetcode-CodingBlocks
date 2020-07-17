class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int profit = 0;
        for(int i=0;i<n-1;i++){
             int x = v[i] - v[i+1];
            if(x<0){
                x= x*(-1);
                profit += x;
            }
        }
        return profit;
    }
};
