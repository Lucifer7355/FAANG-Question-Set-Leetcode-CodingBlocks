class Solution{
public:
    int* a;
    int dp[1001][1001];

    int maxCoinsHelper(int left,int right){
        if(right-left<=1){
            return 0;
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }

        int ans = 0;
        for(int pivot=left+1;pivot<right;pivot++){
            ans = max(ans,a[left]*a[pivot]*a[right] + maxCoinsHelper(left,pivot) + maxCoinsHelper(pivot,right));
        }
        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums){
        int n = nums.size();
        a = new int[n+2];
        a[0] = 1;
        a[n+1] = 1;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            a[i] = nums[i-1];
        }
        return maxCoinsHelper(0,n+1); 
    }
};
