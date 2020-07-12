#include<iostream>
using namespace std;

int minSteps(int n){
    if(n==1){
        return 0;
    }
    if(n%2==0){
        return minSteps(n/2) + 1;
    }else{
        return min(minSteps(n-1)+1,minSteps(n+1)+1);
    }
}

int main(){
    int n;
    cin>>n;
    cout<<minSteps(n);
    return 0;
}

