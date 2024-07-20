include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<pair<int,int>>>adj(n);
    vector<int>cost(n,-1);
    int max_cost =0;
    int tot_trips = 0;
    for(int i =0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back({b-1,c});
    }
    cost[x-1] = 0;
    queue<pair<int,pair<int,int>>>q;
    q.push({x-1,{1e9,0}});
    while(!q.empty())
    {
        int node = q.front().first;
        int cost1 = q.front().second.first;
        int trips = q.front().second.second;
        q.pop();
        if(node == y-1 && cost1 > max_cost) {max_cost = cost1;tot_trips =trips;}
        for(auto it :adj[node])
        {
            int min_cost = min(cost1,it.second);
            if(cost[it.first] == -1)
            {
                cost[it.first] = min_cost;
                q.push({it.first, {min_cost,trips+1}});
            }
            else if(min_cost > cost[it.first])
            {
                cost[it.first] = min_cost;
                q.push({it.first, {min_cost,trips+1}});
            }
        }
    }
   cout<<max_cost<<" "<<tot_trips<<endl;
}

//if(a[i]-st.top()==-1 || a[i]-a[i+1]==1){st.push(a[i]);}