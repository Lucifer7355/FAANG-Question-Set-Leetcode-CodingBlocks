class Solution{
public:
    int longestCommonSubsequence(string s, string t){
        int n = s.size();
        int m = t.size();
        int** dp = new int*[n+1];
        for(int i=0;i<=m;i++){
            dp[i] = new int[n+1];
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[n-i]==t[m-j]){         //s[i-1]==t[j-1]
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans = dp[n][m];
        for(int i=0;i<=m;i++){
            delete []dp[i];
        }
        delete []dp;
        return ans;
    }
};
