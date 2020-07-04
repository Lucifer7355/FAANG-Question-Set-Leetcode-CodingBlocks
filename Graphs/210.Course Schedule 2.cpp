class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
         unordered_map<int,list<int>> m;
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int indegree[numCourses];
        for(int i=0;i<numCourses;i++){
            indegree[i] = 0;
        }
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            for(auto i : m[i]){
                indegree[i]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int> result;
        while(!q.empty()){
            int course = q.front();
            count++;
            result.insert(result.begin(),course);
            q.pop();
            for(auto c : m[course]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push(c);
                }
            }
        }
        vector<int> x;
        return count==numCourses ? result : x;
    }
};
