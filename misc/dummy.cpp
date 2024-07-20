#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<long long> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}
void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            vp[i]={temp,i};
        }
        sort(vp.begin(),vp.end());
        vector<long long> psum(n,0);
        psum[0]=vp[0].first;
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+(long long)(vp[i].first);
        }
        // print(psum);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i;
            int j=i;
            while(j+1<n && psum[j]>=vp[j+1].first){
                j++;
            }
            while(i<=j){
                ans[i]=j;
                i++;
            }
            i--;
            // if(i==n-1)ans[i]=n-1;
            // print(ans);
        }
        vector<int> act(n,0);
        for(int i =0;i<n;i++){
            act[vp[i].second]=ans[i];
        }
        print(act);

    }
  return 0;
}
