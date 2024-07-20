#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long



int recur(int root,int flag,int parent,vector<vector<int>>& adj,vector<vector<int>>& dp){
    if(dp[root][flag]!=-1)return dp[root][flag];
    int take=0,leave=0;
    // cout<<root<<endl;        
    for(auto it:adj[root]){
        if(it!=parent){
            leave+=recur(it,0,root,adj,dp);
        }
    }
    if(flag==0){
        for(auto it:adj[root]){
            if(it!=parent){
                take=max(take,1+leave+recur(it,1,root,adj,dp)-dp[it][0]);
            }
        }
    }

    return dp[root][flag]=max(take,leave);
}



signed main(){
  int n;
  cin>>n;
  vector<vector<int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<vector<int>>dp(n+1,vector<int>(2,-1));
  cout<<recur(1,0,-1,adj,dp)<<endl;
//   for(auto it:dp){
//     for(auto it1:it){
//       cout<<it1<<" ";
//     }
//     cout<<endl;
//   }
  return 0;
}
