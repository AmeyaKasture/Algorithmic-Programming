#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long


void print(vector<vector<int>>& dp){
    for(auto it:dp){
        for(auto itr:it)cout<<itr<<" ";
    cout<<endl;
    }
}


void recur(int root,int parent,vector<vector<int>>& adj,vector<vector<int>>& dp){
//    cout<<root<<" "<<endl;
   
   if(parent!=-1){
        dp[root].push_back(parent);
        int i=0;
        int ancestor=parent;
        while(dp[ancestor].size()>i){
            dp[root].push_back(dp[ancestor][i]);
            ancestor=dp[ancestor][i];
            i++;
        }
   }

    for(auto it:adj[root]){
        // cout<<it<<endl;
        recur(it,root,adj,dp);
    }
}



signed main(){
  int n,q;
  cin>>n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<vector<int>> dp(n+1);
    recur(1,-1,adj,dp);
    // print(dp);
    for (int z=0;z<q;z++){
        int r,k;
        cin>>r>>k;
        int i=0;
        while(k>0){
            // cout<<r<<" "<<i<<endl;
            if(k%2){
                if(dp[r].size()<=i){
                    r=-1;
                    break;
                }
                r=dp[r][i];
            }
            k/=2;
            i++;
        }
        cout<<r<<endl;
    }
  return 0;
}
