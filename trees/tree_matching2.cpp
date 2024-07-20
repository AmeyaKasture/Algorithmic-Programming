#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long



int n;
vector<int> recur(int root,int parent,vector<vector<int>>& adj,vector<vector<vector<int>>>& children,vector<int> &total_children){   
    int sum=0;
    for(auto it:adj[root]){
        if(it!=parent){
            auto temp=recur(it,root,adj,children,total_children);
            children[root].push_back(temp);
            total_children[root]+=temp[0];
            sum+=temp[2];
        }
    }
    return {total_children[root]+1,root,sum+total_children[root]+1};
}


void recur2(int i,int parent,vector<vector<int>>& adj,vector<vector<vector<int>>>& children,vector<int>& dp,int edge){
    if(parent!=-1){
        dp[i]+=dp[parent]+edge;
    }
    int c=0;
    for(auto it:children[i]){
        dp[i]+=it[2];
    }
    for(auto it:children[i]){
        recur2(it[1],i,adj,children,dp,n-1-it[0]+1-it[2]);
    }
}




signed main(){
  
  cin>>n;
  vector<vector<int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<vector<vector<int>>> children(n+1);
  vector<int> total_children(n+1,0);
  recur(1,-1,adj,children,total_children);
  vector<int> dp(n+1,0);
  recur2(1,-1,adj,children,dp,0);
  for(int i=1;i<=n;i++){
    cout<<dp[i]<<" ";
  }
//   for(auto it:children){
//     for(auto itr:it){
//         cout<<"<";
//         for(auto itrd:itr)cout<<itrd<<",";
//         cout<<"> ,";
//     }
//     cout<<endl;
//   }
  return 0;
}
