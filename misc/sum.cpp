#include <bits/stdc++.h>
#include <iostream>
#include<set>
using namespace std;

void print(vector<long long> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}
void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n+1);
        vector<vector<int>>vp(n+1,vector<int>(n+1,0));
        vector<set<int>> vst(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        for(int i=0;i<q;i++){
            int s,d,k;
            cin>>s>>d>>k;
            long long sum=0;
            for(int i=0;i<k;i++){
                int mul=(long long)(i+1);
                if(vst[s+d*i].empty()){
                    vst[s+d*i].insert()
                }
                sum+=((long long)v[s+d*i])*(long long)(i+1);
            }
            cout<<sum<<" ";
        }
        cout<<endl;

    }
  return 0;
}
