class Solution {
public:

    int equalize(int i,int j,string& s1,string& s2){
        if(i==s1.length()){
            return s2.length() - j;
        }
        if(j==s2.length()){
            return s1.length() - i;
        }
        int option1 = 1 + equalize(i,j+1,s1,s2);
        int option2 = 1 + equalize(i,j+1,s1,s2);
        int option3 = (s1[i]==s2[j]) ? equalize(i+1,j+1,s1,s2) : 1 + equalize(i+1,j+1,s1,s2);
        return min(option1,min(option2,option3));
    }

    int topDown(int i,int j,string& s1,string& s2,int **dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==s1.length()){
            return dp[i][j] = s2.length() - j;
        }
        if(j==s2.length()){
            return dp[i][j] = s1.length() - i;
        }

        int option1 = 1 + topDown(i,j+1,s1,s2,dp);
        int option2 = 1 + topDown(i,j+1,s1,s2,dp);
        int option3 = (s1[i]==s2[j]) ? topDown(i+1,j+1,s1,s2,dp) : 1 + topDown(i+1,j+1,s1,s2,dp);
        return dp[i][j] = min(option1,min(option2,option3));
    }

    int minDistanceHelper(int i,int j,string& s1,string& s2){
        int n = word1.length();
        int m = word2.length();
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[m+1];
            for(int j=0;j<=m;j++){
                dp[i][j] = -1;
            }
        }

        int len1 = n;
        int len2 = m;
        for(int i=0;i<=n;i++){
            dp[i][m] = len1;
            len1--;
        }
        for(int i=0;i<=m;i++){
            dp[n][i] = len2;
            len2--;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]!=s2[j]){
                    dp[i][j] = 1 + min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                }else{
                    dp[i][j] = min(dp[i+1][j+1],1+min(dp[i][j+1],dp[i+1][j]));
                }
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2){
        int n = word1.length();
        int m = word2.length();
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[m+1];
            for(int j=0;j<=m;j++){
                dp[i][j] = -1;
            }
        }
        return minDistanceHelper(0,0,word1,word2);
    }
};
