class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        int x = n/2;
        for(int i=x;i>=1;i--){
            v.push_back(i*-1);
        }
        for(int i=1;i<=x;i++){
            v.push_back(i);
        }
        if(n%2==1){
            v.push_back(0);
        }
        return v;
    }
};
