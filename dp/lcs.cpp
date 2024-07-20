int lcs(string&a,string&b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int lcs2(string&a,string&b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9)); 
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool qq=0;
            int ind=-1;
            for(int k=j-1;k>=0;k--){
                if(b[k]==a[i-1]){
                    qq=1;
                    ind=k;
                    break;
                }
            }
            if(qq){
                dp[i][j]=min(1+dp[i-1][ind],dp[i-1][j]);
            }
            else dp[i][j]=1;
        }
    }
    if(dp[n][m]==1e9)dp[n][m]=0;
    return dp[n][m];
}
signed main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
 
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int n1=s1.length(),n2=s2.length(),n3=s3.length();
    int tt;
    cin>>tt;
    int ans1=-1,ans2=-1,ans3=-1;
    int len=lcs(s1,s3);
    if(len==n1)ans3=0;
    else ans3=(int)s1.length();
    
    while(tt--){
        int x;cin>>x;
        if(x==0){
            if(ans1==-1){
                vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
                for(int i=1;i<=n1;i++){
                    for(int j=1;j<=n2;j++){
                        for(int k=1;k<=n3;k++){
                            if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]){
                                dp[i][j][k]=1+dp[i-1][j-1][k-1];
                            }
                            else dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                        }
                    }
                }
                int common=dp[n1][n2][n3];
                int rem=(n1+n2+n3-3*common);
                int one=lcs(s1,s2);
                int two=lcs(s3,s2);
                int three=lcs(s1,s3);
                rem-=(one-common);
                rem-=(two-common);
                rem-=(three-common);
                ans1=common+rem;
            }
            cout<<ans1<<" ";
        }
        else if(x==1){
            if(ans2==-1){
                ans2=lcs2(s1,s2);
            }
            cout<<ans2<<" ";
        }
        else{
            cout<<ans3<<" ";
        }
    }
    return 0;
}