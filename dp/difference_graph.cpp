#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007


int dfs(int i,int j,vector<vector<char>>& adj,vector<vector<int>>& visited,pair<int,int>& min,pair<int,int>& max){
    if(i<0 || j<0 || i>=adj.size() || j>=adj[0].size() || visited[i][j] || adj[i][j]=='.')return 0;
    visited[i][j]=1;
    min.first=min.first>i?i:min.first;
    min.second=min.second>j?j:min.second;
    max.first=max.first<i?i:max.first;
    max.second=max.second<j?j:max.second;
    int cnt=1;
    cnt+=dfs(i+1,j,adj,visited,min,max);
    cnt+=dfs(i-1,j,adj,visited,min,max);
    cnt+=dfs(i,j+1,adj,visited,min,max);
    cnt+=dfs(i,j-1,adj,visited,min,max);
    return cnt;
}




signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){    
        int n,m;
        cin>>n>>m;
        vector<vector<char>> adj(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>adj[i][j];
            }
        }
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> row(n+1,0),col(m+1,0);
        vector<int> dotr(n,0),dotc(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && adj[i][j]=='#'){
                // cout<<i<<" "<<j<<endl;
                pair<int,int> mini={INT_MAX,INT_MAX},maxi={INT_MIN,INT_MIN};
                int cnt = dfs(i,j,adj,visited,mini,maxi);
                ans=max(cnt,ans);
                mini.first=max(0LL,mini.first-1);mini.second=max(0LL,mini.second-1);
                maxi.first=min(n-1,maxi.first+1);maxi.second=min(m-1,maxi.second+1);
                // cout<<cnt<<" "<<mini.first<<" "<<mini.second<<" "<<maxi.first<<" "<<maxi.second<<endl;
                row[mini.first]+=cnt;row[maxi.first+1]-=cnt;
                col[mini.second]+=cnt;col[maxi.second+1]-=cnt;
                }
                if(adj[i][j]=='.'){
                    dotr[i]++;
                    dotc[j]++;
                }
            }
        }
        // for(auto it:row){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        for(int i=1;i<n;i++){
            row[i]+=row[i-1];
        }
        for(int i=1;i<m;i++){
            col[i]+=col[i-1];
        }
        for(int i=0;i<n;i++){
            ans=max(ans,row[i]+dotr[i]);
        }
        for(int i=0;i<m;i++){
            ans=max(ans,col[i]+dotc[i]);
        }
        cout<<ans<<endl;}

    return 0;
}
