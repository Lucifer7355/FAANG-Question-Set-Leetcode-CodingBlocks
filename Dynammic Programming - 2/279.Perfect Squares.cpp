class Solution{
public:
    int numSquares(int n){
        int *dp = new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int ans = INT_MAX;
            for(int j=1;j*j<=i;j++){
                int temp = dp[i-j*j];
                ans = min(ans,temp);
            }
            dp[i] = 1 + ans;
        }
        return dp[n];
    }
};

vector<int> dp(100000, -1);
class Solution{
public:
    int numSquares(int n){
        if(dp[n]!=-1){
            return dp[n];
        }
        
        if(n==0){
            return dp[n] = 0;
        }
        
        int ans = INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+numSquares(n-i*i));
        }
        return dp[n] = ans;
    }
};
