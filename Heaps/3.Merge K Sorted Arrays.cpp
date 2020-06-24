#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,pair<int,int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> v){
    priority_queue<node,vector<node>,greater<node>> pq; //minHeap
    vector<int> result;
                                                                                                                                            
    for(int i=0;i<v.size();i++){
        pq.push({v[i][0],{i,0}});
    }

    while(!pq.empty()){
        node x = pq.top();
        int element = x.first;
        int row = x.second.first;
        int col = x.second.second;
        pq.pop();
        result.push_back(element);
        if((col+1)<v[row].size()){
            pq.push({v[row][col+1],{row,col+1}});
        }
    }
    return result;
}

int main(){
    vector<vector<int>> v{{2,6,12,15},
                          {1,3,14,20},
                          {3,5,8,10}};
    vector<int> output = mergeKSortedArrays(v);
    for(auto i : output){
        cout<<i<<" ";
    }
    return 0;
}

