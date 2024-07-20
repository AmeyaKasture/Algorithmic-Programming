#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007

string test;
int recur(vector<string> &a,vector<vector<int>> &dp,int n,int m,map<char,int> mp[],int i,int j){
    if(j==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    bool flag=0;
    for(int k=0;k<n;k++){
        char c= 
    }
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=a[0].size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    map<char,int> mp[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i][a[i][j]]++;
        }
    }
    recur(a,dp,n,m,mp,-1,0);
    return 0;
}
