#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int ans=0;

int recur(int root,int parent,vector<vector<int>>& adj){
   if(!root)return 0;
   int m1=0,m2=0;
   for(auto it:adj[root]){
       if(it!=parent){
           int temp=0;
           temp=recur(it,root,adj);
           if(temp>=m1){
                m2=m1;
                m1=temp;
              }
              else if(temp>m2){
                m2=temp;
           }
       }
   }
    // cout<<root<<"\t"<<m1<<"\t"<<m2<<endl;
    ans=max(ans,m1+m2+1);
    return m1+1;
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
  recur(1,-1,adj);
  cout<<ans-1<<endl;
//   for(auto it:dp){
//     for(auto it1:it){
//       cout<<it1<<" ";
//     }
//     cout<<endl;
//   }
  return 0;
}
