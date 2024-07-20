#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;
// #define int long long;

vector<int> solve(int number){
    string s= to_string(number);
    int digits=s.size();
    int count=0;
    for(int j=digits-1;s[j]=='0';j--){
        count++;
    }
    vector<int> v={digits,count};
    return(v);
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        set<int> adj[n+1];
        queue<int> q;
        for(int i=0;i<k;i++){
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                cin>>temp[i];
            }
            for(int i=1;i<n-1;i++){
                adj[temp[i]].insert(temp[i+1]);
            }
        }
        vector<int> inDegree(n+1);
        for (int u = 1; u < n+1; u++) {
            for (auto v : adj[u]) {
                inDegree[v]++;
            }
        }
 
        // enqueue vertices with 0 in-degree
        for (int u = 0; u < n+1; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
        int size=0;
        // BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            size++;
 
            // reduce in-degree of adjacent vertices
            for (auto v : adj[u]) {
                inDegree[v]--;
                // if in-degree becomes 0, enqueue the
                // vertex
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        // cout<<size<<endl;x
        if(size-1==n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
  return 0;
}
