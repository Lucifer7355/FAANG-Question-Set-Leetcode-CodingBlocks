class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(auto c : coins){
            for(int i=c; i<=amount;i++){
                dp[i] += dp[i - c];
            }
        }   
        return dp[amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins){
        int m = coins.size();
        int dp[amount+1][m+1];
        for(int i=0;i<=m;i++){
            dp[0][i] = 1;
        }

        for(int i=1;i<=amount;i++){
            dp[i][0] = 0;
        }

        for(int j=1;j<=m;j++){
            for(int i=1;i<=amount;i++){
                int ans = 0;
                ans = dp[i][j-1];
                if(i>=coins[j-1]){
                    ans = ans + dp[i-coins[j-1]][j];
                }
                dp[i][j] = ans;
            }
        }
        return dp[amount][m];
    }
};
