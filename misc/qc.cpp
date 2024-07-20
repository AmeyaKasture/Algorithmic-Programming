#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
#define int long long



void print(vector<int> &v){
    for(auto it:v)cout<<it<<" ";
    cout<<endl;
}

int mini=INT_MAX;
int timer=0;


int32_t main(){
    int n,e;
    cin>>n>>e;
    vector<int> time(n,-1);
    vector<int> ind(n,0);
    vector<int> ind2(n,0);
    vector<int> adj[n];
    vector<int> mint,maxt;
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq2;
    while(e--){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        ind[second]++;
        ind2[second]++;
    }
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            pq.push(i);
            pq2.push(i);
        }
    }
    while(!pq.empty()){
        int temp=pq.top();
        maxt.push_back(temp);
        pq.pop();
        for(auto it:adj[temp]){
            ind[it]--;
            if(ind[it]==0)pq.push(it);
        }
    }
    if(maxt.size()==n){
        while(!pq2.empty()){
            int temp2=pq2.top();
            mint.push_back(temp2);
            pq2.pop();
            for(auto it:adj[temp2]){
                ind2[it]--;
                if(ind2[it]==0)pq2.push(it);
            }
        }
        print(mint);
        print(maxt);
    
    }
    else{
        // for(int i=0;i<n;i++)if(time[i]==-1)dfs(i,time,adj);
        // print(time);
        // cout<<endl;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(time[i]==-1){
                q.push(i);
                // print(time);
                while(!q.empty()){
                    int tt=q.size();
                    while(tt--){
                        int it=q.front();
                        q.pop();
                        if(time[it]!=-1)continue;
                        time[it]=timer;
                        for(auto itr:adj[it]){
                            if(time[itr]==-1)q.push(itr);
                            else  {
                                // cout<<i<<"\t"<<it<<"\t"<<time[i]<<"\t"<<timer<<endl;
                                mini=min(mini,timer+1-time[itr]);
                            }
                        }
                    }
                    timer++;
                }
            }
        }
        
        // for(int i=0;i<n;i++)cout<<i<<" ";
        // cout<<endl;
        cout<<mini<<endl;
    }

    return 0;
}
