#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}


int main(){
    int t;
    cin>> t;
    while(t--){
        int n=0;
        int x=0;
        int k=0;
        cin>>n>>k>>x;
        vector<int> v(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v[i]=temp;
            sum+=v[i]; 
        }
        sort(v.rbegin(),v.rend());
        vector<int> vb(n,0);
        for(int i=0;i<n;i++){
            // cout<<i<<endl;
            for(int j=i;j<n && j-i<x;j++){
                // cout<<i<<j<<endl;
                vb[i]+=v[j];
            }
        }
        // print(v);
        // print(vb);
        int maxi=-sum;
        // cout<<sum<<endl;
        maxi=max(sum-2*vb[0],maxi);
        for(int i=1;i<=k;i++){
            
            sum-=v[i-1];
            if(i<n)maxi=max(sum-2*vb[i],maxi);
        }
        if(k==n)maxi=max(0,maxi);
        cout<<maxi<<endl;

       

    }
    return 0;  
}
