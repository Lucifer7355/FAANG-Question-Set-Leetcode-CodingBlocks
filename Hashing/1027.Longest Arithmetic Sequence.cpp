class Solution {
public:
    int longestArithSeqLength(vector<int>& A){
        int n = A.size();
        if(n==1){
            return 1;
        }
        unordered_map<int,list<int>> m;
        int result = 2;
        for(int i=0;i<n;i++){
            m[A[i]].push_back(i);
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int count = 2;
                int d = A[j] - A[i];
                int num = A[j] + d;
                int pos = j;
                while(m.find(num)!=m.end()){
                    bool flag = false;
                    for(auto node : m[num]){
                        if(node>pos){
                            count++;
                            num = num + d;
                            flag = true;
                            pos = node;
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
                result = max(result,count);
            }
        }
        return result;
    }
};
