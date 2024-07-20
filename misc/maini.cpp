
#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}
vector<int> factors(int n){
    vector<int> fac;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            fac.push_back(i);
            fac.push_back(n/i);
        }
    }
    return fac;
}

bool checker(vector<int> &v,int k){
    int n =v.size();
    int num=n/k;
    for(int i=0;i<k;i++){
        int m = v[i]
    }
}

int main(){
    int t;
    cin>> t;
    while(t--){
        int n=0;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
       
       

    }
    return 0;  
}
