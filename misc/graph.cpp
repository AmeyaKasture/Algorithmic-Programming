#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    int start,end;
    cin>>start>>end;
    for(int i=0;i<m;i++){
        int k,j,c;
        cin>>k>>j>>c;
        adj[k].push_back({j,c});
    }
    vector<pair<int,int>> visited(n+1,{-1,0});
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int loc=q.front();
        q.pop();
        // cout<<loc<<endl;
        for(auto it:adj[loc]){
            int next =it.first;
            int cost=it.second;
            if(visited[loc].first!=-1 && (visited[loc].first<cost))cost=visited[loc].first;
            if(visited[next].first<cost || (visited[next].first==cost && visited[next].second>=visited[loc].second+1)){
                visited[next]={cost,visited[loc].second+1};
                q.push(next);
            }
        }
    }
    if(visited[end].first==-1)visited[end].first=0;
    cout<<visited[end].first<<" "<<visited[end].second;

    return 0;
}




