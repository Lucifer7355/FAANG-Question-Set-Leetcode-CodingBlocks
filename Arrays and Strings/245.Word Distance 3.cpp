#include<bits/stdc++.h>
using namespace std;
 
int shortestWordDistance(vector<string>& words,string word1,string word2){
   int n = words.size();
   int ans = n;
   if(word1==word2){
       int p = -1;
       for(int i=0;i<n;i++){
           if(words[i]==word1){
               if(p==-1){
                   p = i;
               }else{
                   ans = min(ans,i-p);
                   p = i;
               }
           }
       }
   }else{
       int w1 = -1;
       int w2 = -1;
       for(int i=0;i<n;i++){
           if(words[i]==word1){
               w1 = i;
           }
           if(words[i]==word2){
               w2 = i;
           }
           if(w1!=-1 && w2!=-1){
               ans = min(ans,abs(w1-w2));
           }
       }
   }
   return ans;
}
 
int main(){
   int n;
   cin>>n;
   vector<string> words;
   for(int i=0;i<n;i++){
       string x;
       cin>>x;
       words.push_back(x);
   }
   string word1,word2;
   cin>>word1>>word2;
   cout<<shortestWordDistance(words,word1,word2);
   return 0;
}

