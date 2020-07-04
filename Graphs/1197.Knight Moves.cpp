#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        map<pair<int,int>,list<pair<int,int> > > ml;
    public:
        void addEdge(int i,int j,int n,int m){
            pair<int,int> p = make_pair(i,j);
            if(i+2<n){
                if(j+1<m){
                    ml[p].push_back(make_pair(i+2,j+1));
                }
                if(j-1>=0){
                    ml[p].push_back(make_pair(i+2,j-1));
                }
            }
            if(i-2>=0){
                if(j+1<m){
                    ml[p].push_back(make_pair(i-2,j+1));
                }
                if(j-1>=0){
                    ml[p].push_back(make_pair(i-2,j-1));
                }
            }
            if(i+1<n){
                if(j+2<m){
                    ml[p].push_back(make_pair(i+1,j+2));
                }
                if(j-2>=0){
                    ml[p].push_back(make_pair(i+1,j-2));   
                }
            }
            if(i-1>=0){
                if(j+2<m){
                    ml[p].push_back(make_pair(i-1,j+2));
                }
                if(j-2>=0){
                    ml[p].push_back(make_pair(i-1,j-2));
                }
            }
            return;
        }

        int bfs(int s1,int s2,int e1,int e2,int n,int m){
            pair<int,int> src = make_pair(s1,s2);
            pair<int,int> dest = make_pair(e1,e2);

            map<pair<int,int>,bool> visited;
            map<pair<int,int>,int> distance;
            queue<pair<int,int>> q;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    visited[make_pair(i,j)] = false;
                    distance[make_pair(i,j)] = INT_MAX;
                }
            }

            q.push(src);
            visited[src] = true;
            distance[src] = 0;

            while(!q.empty()){
                pair<int,int> node = q.front();
                q.pop();

                for(auto child : ml[node]){
                    if(!visited[child]){
                        visited[child] = true;
                        distance[child] = distance[node] + 1;
                        q.push(child);
                    }
                }
            }

            return distance[dest]==INT_MAX ? -1 : distance[dest]; 
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    int s1,s2,e1,e2;
    cin>>s1>>s2>>e1>>e2;
    Graph g;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            g.addEdge(i,j,n,m);
        }
    }
    s1--;
    s2--;
    e1--;
    e2--;
    cout<<g.bfs(s1,s2,e1,e2,n,m);
    return 0;
}
