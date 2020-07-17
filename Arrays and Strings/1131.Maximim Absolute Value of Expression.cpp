class Solution {
public:
    int maxAbsValExpr(vector<int>& a, vector<int>& b){
        int n = a.size();
        int a1,b1,c1,d1;
        int a2,b2,c2,d2;
        a1 = b1 = c1 = d1 = INT_MIN;
        a2 = b2 = c2 = d2 = INT_MAX;
        for(int i=0;i<n;i++){
            a1 = max(a1,a[i]+b[i]+i);
            a2 = min(a2,a[i]+b[i]+i);

            b1 = max(b1,b[i]-a[i]+i);
            b2 = min(b2,b[i]-a[i]+i);

            c1 = max(c1,b[i]+a[i]-i);
            c2 = min(c2,b[i]+a[i]-i);

            d1 = max(d1,b[i]-a[i]-i);
            d2 = min(d2,b[i]-a[i]-i);
        }
        int temp1 = a1-a2 > b1-b2 ? a1-a2 : b1-b2;
        int temp2 = c1-c2 > d1-d2 ? c1-c2 : d1-d2;
        return temp1 > temp2 ? temp1 : temp2; 
    }
};
