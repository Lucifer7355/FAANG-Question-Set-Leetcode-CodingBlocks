#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int odd_count = 0;
        int even_count = 0;
        for(int i=0;i<s.size();i++){
            if(i%2!=0 && s[i]=='1'){
                odd_count++;
            }
            if(i%2==0 && s[i]=='1'){
                even_count++;
            }
        }
        (2*odd_count + even_count)%3 == 0 ? cout<<"1"<<endl : cout<<"0"<<endl;
    }
    return 0;
}

