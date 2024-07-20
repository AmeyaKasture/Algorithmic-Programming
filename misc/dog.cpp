#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

int mod=1000000007;

int recur(int i,int j, int di,int dj,vector<vector<int>> & dp){
    if(i>di|| j>dj)return 0;
    if(i==di && j==dj )return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int left=0,up=0;
    left=recur(i+1,j,di,dj,dp);
    up=recur(i,j+1,di,dj,dp);
    return dp[i][j]=(left+up)%mod;

}


int32_t main(){
  int si,sj,di,dj;
  cin>>si>>sj>>di>>dj;
  int right=si-di;
  int up = sj-dj;
  cout<<abs(right)+abs(up)<<" ";
  vector<vector<int>> dp(2002,vector<int>(2002,-1));
  cout<<recur(0,0,abs(right),abs(up),dp)<<" ";
  if(up==0|| right==0)cout<<0<<" "<<0<<endl;
  else{
    cout<<1<<" ";
    right=abs(right);
    up=abs(up);
    int ans=min(right,up);
    if(right==up)cout<<2*ans-1<<endl;
    else cout<<2*ans<<endl;
  }
  return 0;
}
