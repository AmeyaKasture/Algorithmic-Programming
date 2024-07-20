#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007

void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}

ll sq(long long n,vector<int> &primes){
    ll left = 0;
    ll right= primes.size();
    ll ans=-1;
    while(left<=right){
        ll mid=(left+right)/2;
        if(pow(primes[mid],2)<n)left=mid+1;
        else if(pow(primes[mid],2)>n)right=mid-1;
        else return primes[mid];
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n=1;
    cin>>n;
    // vector<int> v;  
    vector<int> v(1e6,1);
    vector<int> primes;
    for(int i =2;i<1e6;i++){
        if(v[i]==0)continue;
        if(v[i]==1)primes.push_back(i);
        for(int j=i*2;j<1e6;j=j+i){
            // if(i==991){
            //     cout<<j<<endl;
            // }
            v[j]=0;
        }
    }
    // cout<<v[991]<<endl;

    while(n--){
        long long temp;
        cin>>temp;
        ll ans= sq(temp,primes);
        // cout<<ans<<"\t"<<temp<<"\t"<<endl;
        if(ans==-1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    
    return 0;
}
