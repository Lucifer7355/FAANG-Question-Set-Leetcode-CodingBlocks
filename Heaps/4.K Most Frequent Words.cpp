class Solution {
public:
    struct compare{
        bool operator()(pair<int,string> p1,pair<int,string> p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }else{
                return p1.first>p2.first;  //For creating a minHeap
            }    
        };   
    };
    
    vector<string> topKFrequent(vector<string>& words, int k){
        unordered_map<string,int> m;
        for(auto i : words){
            m[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq; 
        for(auto i : m){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> result;
        while(k--){
            result.insert(result.begin(),pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};
