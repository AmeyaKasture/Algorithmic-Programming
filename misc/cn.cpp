#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
#define int long long



void print(vector<int> &v){
    for(auto it:v)cout<<it<<" ";
    cout<<endl;
}

int solver1(vector<int> adj[],vector<int> & ind,int n){
 
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> maxt;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            pq.push(i);
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
    if(maxt.size()!=n)return -1;
    vector<int> left(n);
    vector<int> right(n);
    left[0]=1;
    for(int i=1;i<n;i++){
        if(maxt[i]>maxt[i-1]){
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }
    right[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(maxt[i]>maxt[i+1]){
            right[i]=right[i+1]+1;
        }
        else{
            right[i]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(left[i],right[i]);
    }
    return ans;
}

int solver2(vector<int> adj[],vector<int> & ind2,int n){
    priority_queue<int> pq2;
    for(int i=0;i<n;i++){
        if(ind2[i]==0){
            pq2.push(i);
        }
    }
    vector<int> mint;
    while(!pq2.empty()){
            int temp2=pq2.top();
            mint.push_back(temp2);
            pq2.pop();
            for(auto it:adj[temp2]){
                ind2[it]--;
                if(ind2[it]==0)pq2.push(it);
            }
    }
    if(mint.size()!=n)return -1;
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    int counter=0;
    int boundary=mint[0];
    int bound=0;
    int i=0;
    while(i<n){
       
        if(i>bound)return -1;
        if(i==bound){
            boundary=max(boundary,i+mint[i]);
            bound=boundary;
            if(boundary>=n-1)return counter+1;
            counter++;
            i++;
            continue;
        }
        while(i!=bound){
            boundary=max(boundary,i+mint[i]);
            if(boundary>=n-1)return counter+1;
            i++;
        }
    }
    if(dp[n-1]==INT_MAX)return -1;
    return dp[n-1];

}

int32_t main(){
    int n,e,mode;
    cin>>n>>e>>mode;
    vector<int> ind(n,0);
    vector<int> ind2(n,0);
    vector<int> adj[n];
    while(e--){
        int first,second;
        cin>>first>>second;
        adj[first].push_back(second);
        ind[second]++;
        ind2[second]++;
    }
    if(mode==1)cout<<solver1(adj,ind,n);
    else cout<<solver2(adj,ind2,n);
   
    

    return 0;
}


int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int> > arr2(n);
    for (int i = 0; i < n; i++) {
        arr2[i] = { arr[i], dep[i] };
    }
    // Sort arr2 based on arrival time
    sort(arr2.begin(), arr2.end());
    priority_queue<int, vector<int>, greater<int> > p;
    int count = 1;
    p.push(arr2[0].second);
    for (int i = 1; i < n; i++) { 
        // Check if arrival time of current train
        // is less than or equals to departure time
        // of previous train
        if (p.top() >= arr2[i].first) {
            count++;
        }
        else {
            p.pop();
        }
        p.push(arr2[i].second);
    }
    return count;
}