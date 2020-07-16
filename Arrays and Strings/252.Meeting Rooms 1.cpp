#include<bits/stdc++.h>
using namespace std;
 
bool compare(pair<int,int> p1,pair<int,int> p2){
   return p1.second<p2.second;
}
 
bool canAttendMeetings(vector<pair<int,int>>& intervals){
   int n = intervals.size();
   sort(intervals.begin(),intervals.end(),compare);
   for(int i=1;i<n;i++){
       if(intervals[i].first<intervals[i-1].second){
           return false;
       }
   }
   return true;
}
 
int main(){
   int n;
   cin>>n;
   vector<pair<int,int>> intervals;
   for(int i=0;i<n;i++){
       int start,end;
       cin>>start>>end;
       intervals.push_back(make_pair(start,end));
   }
   if(canAttendMeetings(intervals)){
       return "true";
   }else{
       return "false";
   }
}

