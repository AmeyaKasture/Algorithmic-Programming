#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007


vector<int> solve(int n, int q,vector<int> &arr,vector<vector<int>> que){
    //create a prefix sum array
    vector<int> prefix(n+1,0); 
    vector<int> ans;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    };
    for(auto it:que){
        int type= it[0];
        int l=it[1];
        int r=it[2];
        for(auto it:prefix){
            cout<<it<<" ";
        }
        cout<<endl;
        if(type==1){
            for(int i =l;i<=n;i++){
                prefix[i]+=r-arr[l-1]; 
            }
            arr[l-1]=r;
        }
        else{
            int sum=0;
            for(int i=l;i<=r;i++){
                sum+=prefix[r]-prefix[i-1];
            }
            ans.push_back(sum);
        }
    }
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> que(q,vector<int>(3));
    while(q--){
        cin>>que[q][0]>>que[q][1]>>que[q][2];
    }
    vector<int> ans=solve(n,q,arr,que);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
