class Solution {
public:
    void decode(string str,int &id,string &operation, int &time){
        int j = 0;
        id = time = 0;
        while(str[j]!=':'){
            id = id*10 + str[j] - '0';
            j++;
        }
        j++;
        while(str[j]!=':'){
            operation.push_back(str[j]);
            j++;
        }
        j++;
        while(j<str.size()){
            time = time*10 + str[j] - '0';
            j++;
        }
        if(operation == "end"){
            time++;
        }
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> duration(n,0);
        stack<int> s;
        int prev_op_time;
        for(int i=0;i<logs.size();i++){
            int id,time;
            string operation;
            decode(logs[i],id,operation,time);
            if(!s.empty()){
                duration[s.top()] += (time - prev_op_time); 
            }
            prev_op_time = time;
            if(operation=="start"){
                s.push(id);
            }else{
                s.pop();
            }
        }
        return duration;
    }
};
