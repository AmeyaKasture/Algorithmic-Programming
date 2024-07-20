#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007



int solve(string s,vector<int> count[],vector<vector<int>>&dp,vector<int> &arr,int i,int k){
    if((i<s.size() &&k==0) || i==s.size() && k>0){
        return 0;
    }
    if(i==s.size() && k==0){
        return 1;
    }
    // if(dp[i][k]!=-1){
    //     return dp[i][k];
    // }
    int ans=0;
    int cut=0,uncut=0;
    vector<int> temp[26]=count;
    for(int d=i+1;d<s.size();d++){
        for(int j=0;j<26;j++){
            count[d][j]-=count[i][j];
        }
    }
    cut=solve(s,count,dp,arr,i+1,k-1);
    count=temp;
    if(count[i][s[i]-'a']<arr[s[i]-'a']){
        uncut=solve(s,count,dp,arr,i+1,k);
    }
    cout<<i<<" "<<k<<" "<<cut<<" "<<uncut<<endl;
    ans=cut+uncut;
    return dp[i][k]=ans;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> arr(26);
    for(int i=0;i<26;i++)cin>>arr[i];
    int k;
    cin>>k;
    cout<<n<<" "<<s<<" "<<k<<endl;
    vector<int> count[n+1];
    vector<vector<int>> dp(n,vector<int>(k,-1));
    for(int i=0;i<n+1;i++){
         count[i].resize(26,0);
    }
   
    count[0][s[0]-'a']++;
    for(int i=1;i<n;i++){
        count[i]=count[i-1];
        count[i][s[i]-'a']++;
    }

    cout<<solve(s,count,dp,arr,0,k);
    return 0;
}
