class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix){
        int n = matrix.size();
        if(n==0){
            return 0;
        }
        int m = matrix[0].size();
        if(n==0 || m==0){
            return 0;
        }
        int** dp = new int*[n];
        for(int i=0;i<n;i++){
            dp[i] = new int[m];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i][0] = matrix[i][0] - '0';
            if(dp[i][0]==1){
                ans = 1;
            }
        }
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i] - '0';
            if(dp[0][i]==1){
                ans = 1;
            }
        }
        
        int temp = INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                    temp = dp[i][j];
                }else{
                    dp[i][j] = 0;
                }
                ans = max(ans,temp);
            }
        }
        return ans*ans;
    }
};
