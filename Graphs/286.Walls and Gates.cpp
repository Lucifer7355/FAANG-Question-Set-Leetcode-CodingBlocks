#include <bits/stdc++.h>
using namespace std;

void wallsAndGates(vector<vector<int>>& rooms){
    vector<vector<int>> result;
    queue<pair<int,int>> q;
    int n = rooms.size();
    if(n==0){
        return;
    }
    int m = rooms[0].size();
    vector<vector<bool>> visited;
    for(int i=0;i<n;i++){       //Mark all Cells as False
        visited.push_back({});
        for(int j=0;j<m;j++){
            visited[i].push_back(false);
        }
    }
    for(int i=0;i<n;i++){
        result.push_back({});
        for(int j=0;j<m;j++){
            if(rooms[i][j]==0){
                q.push(make_pair(i,j));
                visited[i][j] = true;
                result[i].push_back(0);
            }else{
                result[i].push_back(-1);
            }
        }
    }
    while(!q.empty()){
        pair<int,int> cell = q.front();
        q.pop();
        if((cell.first+1<n) && (!visited[cell.first+1][cell.second]) && (rooms[cell.first+1][cell.second]!=-1)){
            result[cell.first+1][cell.second] = result[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first+1,cell.second));
            visited[cell.first+1][cell.second] = true;
        }
        if((cell.first-1>=0) && (!visited[cell.first-1][cell.second]) && (rooms[cell.first-1][cell.second]!=-1)){
            result[cell.first-1][cell.second] = result[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first-1,cell.second));
            visited[cell.first-1][cell.second] = true;
        }
        if((cell.second+1<m) && (!visited[cell.first][cell.second+1]) && (rooms[cell.first][cell.second+1]!=-1)){
            result[cell.first][cell.second+1] = result[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first,cell.second+1));
            visited[cell.first][cell.second+1] = true;
        }
        if((cell.second-1>=0) && (!visited[cell.first][cell.second-1]) && (rooms[cell.first][cell.second-1]!=-1)){
            result[cell.first][cell.second-1] = result[cell.first][cell.second] + 1;
            q.push(make_pair(cell.first,cell.second-1));
            visited[cell.first][cell.second-1] = true;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rooms[i][j]>0){
                if(result[i][j]==-1){
                    result[i][j] = 2147483647; 
                }
                rooms[i][j] = result[i][j];
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> rooms;
    for(int i=0;i<n;i++){
        rooms.push_back({});
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            rooms[i].push_back(x);
        }
    }

    wallsAndGates(rooms);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<rooms[i][j]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}
