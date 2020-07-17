class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        int n = arr.size();
        int currentSum = 0;
        int sum = 0;
        int pos = 0;
        for(int i=0;i<k;i++){
            currentSum = currentSum + abs(x - arr[i]);
            sum = currentSum;
            pos = 0;
        }
        for(int i=1;i<=n-k;i++){
            currentSum = currentSum - abs(x - arr[i-1]);
            currentSum = currentSum + abs(x - arr[i+k-1]);
            if(sum>currentSum){
                sum = currentSum;
                pos = i;
            }
        }
        vector<int> result;
        for(int i=pos;i<pos+k;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};


