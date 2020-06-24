class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(pq.size()<K || pq.top()>dist){
                if(pq.size()==K){
                    pq.pop();
                }
                pq.push(dist);
            }
        }
        int num = pq.top();
        int i = 0;
        int j = n - 1;
        while(i<=j){
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(dist<=pq.top()){
                i++;
            }else{
                swap(points[i],points[j]);
                j--;
            }
        }
        points.erase(points.begin()+K,points.end());
        return points;
    }
};
