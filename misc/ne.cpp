#include <bits/stdc++.h>
#include <iostream>
#include<set>
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
        long long n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int diff= b/a;
        long long prev=0;
        bool ans=true;
        for(int i=0;i<n;i++){
            if(v[i]-prev>=diff){
                f=f-b;
                prev=v[i];
            }
            else{
                f= f - (long long)a*(long long)(v[i]-prev);
                prev=v[i];
            }
            if(f<=0){
                ans=false;
                break;
            }
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
  return 0;
}
