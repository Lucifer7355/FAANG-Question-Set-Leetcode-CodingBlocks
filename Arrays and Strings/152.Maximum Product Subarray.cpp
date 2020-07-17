class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int pos = 1;
        int neg = 1;
        int maxPro = INT_MIN; 
        bool hasPos = false;
        bool hasZero = false;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                hasPos = true;
                pos = pos*nums[i];
                if(neg!=1){
                    neg = neg*nums[i];
                }
            }else if(nums[i]<0){
                int temp = pos;
                if(neg*nums[i]==1){
                    hasPos = true;
                }
                pos = max(1,neg*nums[i]);
                neg = temp*nums[i];
            }else{
                pos = 1;
                neg = 1;
                hasZero = true;
            }
            maxPro = max(maxPro,pos);
        }
        if(maxPro==1){
            if(hasPos){
                return maxPro;
            }
            if(hasZero){
                return 0;
            }
        }
        return maxPro;
    }
};
