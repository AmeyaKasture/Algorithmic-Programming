#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007


int check(char c){
    if(c=='a') return 1;
    else if(c=='e') return 2;
    else if(c=='i') return 3;
    else if(c=='o') return 4;
    else if(c=='u') return 5;
    else return 0;
}

pair<int,int> recur(string s,vector<vector<pair<int,int>>> &dp,int i,int j){
    if(i>=s.size()){
        if(j!=5)return{0,0};
        else return {0,1};
    }
    if(dp[i][j].first!=-1){
        return dp[i][j];
    }
    int ans=0;
    int val=check(s[i]);
    bool flag=0;
    auto p=recur(s,dp,i+1,j);
    if(p.second==1){
        ans=max(ans,p.first);
        flag=1;
    }
    if(val==j || val==j+1){
        p=recur(s,dp,i+1,val);
        if(p.second==1){
            ans=max(ans,1+p.first);
            flag=1;
        }
    }
    return dp[i][j]={ans,flag};
    
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);//
    string s;
    cin>>s;
    int n =s.size();
    vector<vector<int>> dp(n+1,vector<int>(7,0));
    cout<<n<<endl;
    // auto ans= recur(s,dp,0,0);
    // dp[n][5]=1;
    // cout<<dp[9][5].first<<" "<<dp[8][5].second<<endl;
    for(int i=n-1;i>=0;i--){
        for(int j=5;j>=0;j--){
            int ans=0;
            int val=check(s[i]);
            if(val==j || val==j+1){
                ans=max(ans,1+dp[i+1][val]);
            }
            ans=max(ans,dp[i+1][j]);
        }
    }
    //print dp first element
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
 