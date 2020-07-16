class Solution {
public:
    
    int update(int n){
        int sum = 0;
        while(n!=0){
            int x = n%10;
            n = n/10;
            sum = sum + x*x;
        }
        return sum;
    }
    
    bool check(int n,unordered_map<int,bool>& m){
        if(n==1){
            return true;
        }
        if(m.find(n)!=m.end()){
            return false;
        }
        m.insert(make_pair(n,true));
        n = update(n);
        return check(n,m);
    }
    
    bool isHappy(int n){
        unordered_map<int,bool> m;
        return check(n,m);
    }
};
