#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int test=1;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        bool flag =true;
        vector<vector<ll>> matr(n,vector<ll>(n,-1));
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++)cin>>matr[i][j];
        }
        vector<ll> arr(n,(1<<30)-1);
        for(int i=0;i<n && flag;i++){
            for(int j=0;j<n && flag;j++){
                if(i==j)continue;
                ll temp = arr[i]|arr[j];
                if(((temp^((1<<30)-1))& matr[i][j])>0){
                    // cout<<i<<"\t"<<j<<"\t"<<temp<<endl;
                    flag=false;
                    break;
                }
                else{
                    arr[i]=arr[i]& matr[i][j];
                    arr[j]=arr[j]& matr[i][j];
                    // for(auto it:arr)cout<<it<<"  ";
                }
            }
        }
        for(int i=0;i<n && flag;i++){
            for(int j=0;j<n && flag;j++){
                if(i==j)continue;
                ll temp = arr[i]|arr[j];
                if(((temp^((1<<30)-1))& matr[i][j])>0){
                    // cout<<i<<"\t"<<j<<"\t"<<temp<<endl;
                    flag=false;
                    break;
                }
                else{
                    arr[i]=arr[i]& matr[i][j];
                    arr[j]=arr[j]& matr[i][j];
                    // for(auto it:arr)cout<<it<<"  ";
                }
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
            for(auto it:arr)cout<<it<<"  ";
            cout<<endl;
        }
    }
    return 0;
}
