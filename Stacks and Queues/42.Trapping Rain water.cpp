class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        if(n==0){
            return 0;
        }
        int left[n];
        int right[n];

        left[0] = 0;
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i-1]);
        }

        right[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i+1]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int level = min(left[i],right[i]);
            if(level - height[i] > 0){
                ans = ans + level - height[i];
            }
        }
        return ans;
    }
};
