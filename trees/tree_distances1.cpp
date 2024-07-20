#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int ans=0;
int n;
int recur(int root,int parent,vector<vector<int>>& adj,set<pair<int,int>,greater<pair<int,int>>> s[],vector<int>& parents){
   if(!root)return 0;
   for(auto it:adj[root]){
       if(it!=parent){
          parents[it]=root;
          s[root].insert({recur(it,root,adj,s,parents),it});
       }
   }
   if(s[root].empty())return 1;
   return s[root].begin()->first+1;
}


void recur2(int i,vector<vector<int>>& adj,set<pair<int,int>,greater<pair<int,int>>> s[],vector<int>& parent,vector<int>& ans){
    if(parent[i]!=0){
        int temp=0;
        for(auto it:s[parent[i]]){
            if(it.second!=i){
                temp=1;
                s[i].insert({it.first+1,parent[i]});
                break;
            }
        }
        if(temp==0){
            s[i].insert({1,parent[i]});
        }
    }
    ans[i]=s[i].begin()->first;
    for(auto it:adj[i]){
        if(it!=parent[i]){
            recur2(it,adj,s,parent,ans);
        }
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
  set<pair<int,int>,greater<pair<int,int>>>s[n+1];
  vector<int> parent(n+1,0);
  recur(1,-1,adj,s,parent);
  vector<int>ans(n+1,0);
  recur2(1,adj,s,parent,ans);
    // for(int i=1;i<=n;i++){
    //     int temp=s->begin()->first;
    //     for(auto it:s[parent[i]]){
    //         if(it.second!=i){
    //             temp=max(temp,it.first+1);
    //             break;
    //         }
    //     }
    //     ans[i]=temp;
    // }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
//   for(auto it:dp){
//     for(auto it1:it){
//       cout<<it1<<" ";
//     }
//     cout<<endl;
//   }
  return 0;
}
