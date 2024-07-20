#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007



signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        map<int,int> mp;
        int maxi=INT_MIN;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
            maxi=max(maxi,arr[i]);
        }
        int odds=0;
        int ans=0;
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int> a;
                for(int j=i;j<n;j++){
                    if((arr[j]-arr[i])%k==0){
                        a.push_back(arr[j]);
                        visited[j]=1;
                    }
                }
                dp.push_back(a);
            }
        }
        for(auto a:dp){
            // cout<<a.size()<<endl;
            int sum=0;
            int l=a.size();
            vector<int> diff(l,0);
            int ms=INT_MIN;
            // for(auto it:a)cout<<it<<" ";
            // cout<<endl;
            if(l!=1){
                if(a.size()%2==1){
                    odds++;
                    
                    sum-=ms;
                }
                else{
                    for(int i=1;i<l;i+=2){
                       sum+=(a[i]-a[i-1])/k;
                    }
                }
            }
            else odds++;
            ans+=sum;
        }

        if(odds>1)cout<<-1<<endl;
        else cout<<ans<<endl;
        


    }
  
    return 0;
}
