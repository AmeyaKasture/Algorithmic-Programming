#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long


int recur(int root,vector<vector<int>>& adj,vector<int>& ans){
    int sum=0;
    for(auto it:adj[root]){
        sum+=recur(it,adj,ans);
    }
    ans[root]=sum;
    return sum+1;
}



signed main(){
  int n;
  cin>>n;
  vector<vector<int>> adj(n+1);
  for(int i=2;i<=n;i++){
     int x;
     cin>>x;
     adj[x].push_back(i);
  }
    vector<int> ans(n+1,0);
    recur(1,adj,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

  return 0;
}
