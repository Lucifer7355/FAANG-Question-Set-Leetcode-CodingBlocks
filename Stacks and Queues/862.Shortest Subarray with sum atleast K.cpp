class Solution {
public:
    int shortestSubarray(vector<int>& A, int k){
        vector<int> prefixSum;
        prefixSum.push_back(A[0]);
        for(int i=1;i<A.size();i++){
            prefixSum.push_back(A[i] + prefixSum[i-1]);
        }
        deque<pair<int,int>> q;
        q.push_back({0,-1});
        int ans = INT_MAX;
        for(int i=0;i<A.size();i++){
            while(!q.empty() && prefixSum[i] - q.front().first >= k){
                ans = min(ans,i - q.front().second);
                q.pop_front();
            }
            while(!q.empty() && prefixSum[i]<=q.back().first){
                q.pop_back();
            }
            q.push_back({prefixSum[i],i});
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
