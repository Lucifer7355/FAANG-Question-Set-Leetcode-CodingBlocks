class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          int extra = 0,index=0,total=0;
        for(int i=0; i<gas.size(); i++) {
            total += gas[i] - cost[i];
            extra += gas[i] - cost[i];
            if(extra < 0) {
                extra = 0;
                index = i+1;
            }
        }
        if(total>=0) return index;
        else return -1;
    }
};
