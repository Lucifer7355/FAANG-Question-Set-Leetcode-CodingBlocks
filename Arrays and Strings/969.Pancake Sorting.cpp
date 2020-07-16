class Solution {
public:    

    void flip(vector<int>& A,int k){
        for(int i=0;i<k/2;i++){
            int temp  = A[i];
            A[i] = A[k-i-1];
            A[k-1-i] = temp;
        }
    }

    int find(vector<int>& A,int n){
        int index = 0;
        for(int i=1;i<n;i++){
            if(A[i]>A[index]){
                index = i;
            }
        }
        return index;
    }

    vector<int> pancakeSort(vector<int>& A){
        vector<int> result;    
        int n = A.size();
        while(n>0){
            int index = find(A,n);
            if(index!=n-1){
                flip(A,index+1);
                flip(A,n);
                result.push_back(index+1);
                result.push_back(n);
            }
            n--;
        }
        return result;
    }
};
