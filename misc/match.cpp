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
       int n;
       cin>>n;
       string a,b,c;
       cin>>a>>b>>c;
       int count=0;
       bool ans=true;
       for(int i=0;i<n;i++){
            if((a[i]!=c[i]&& b[i]!=c[i])){
                count++;
            }
       }
       if(count< 1)ans=false;
       if(ans)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
       

    }
    return 0;   
}
