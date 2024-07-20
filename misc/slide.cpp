
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<long long> & v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        print(v);
        int mini=0;
        int i=0,j=1;
        while(j<n){
            if(v[j]-v[i]>=d){ 
                cout<<i<<"\t"<<j<<endl;
                mini=max(mini,j-i+1);
                i++;
            }
            else{
                j++;
            }
        }
       cout<<mini<<endl;

    }
}  