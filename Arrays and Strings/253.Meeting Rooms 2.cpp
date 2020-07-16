#include<bits/stdc++.h>
using namespace std;
 
int meetingRooms(vector<int>& s,vector<int>& e){
   int n = s.size();
   sort(s.begin(),s.end());
   sort(e.begin(),e.end());
   int i=0;
   int j=0;
   int halls = 0;
   int result = 0;
   while(i<n && j<n){
       if(s[i]<e[j]){
           halls++;
           i++;
       }else{
           halls--;
           j++;
       }
       result = max(result,halls);
   }
   return result;
}
 
int main(){
   int n;
   cin>>n;
   vector<int> s;
   vector<int> e;
   for(int i=0;i<n;i++){
       int start,end;
       cin>>start>>end;
       s.push_back(start);
       e.push_back(end);
   }
   cout<<meetingRooms(s,e);
   return 0;
}

