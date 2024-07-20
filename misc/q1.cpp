#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007

bool is_valid(int n,int m ,int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n<=2){
            cout<<stoi(s)<<endl;
        }
        else if(n==3 && s[1]=='0'){
            cout<<min(s[0]-'0' +s[2]-'0',(s[0]-'0')*(s[2]-'0'))<<endl;
        }
        else{
            bool flag=false;
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    flag=true;
                    break;
                }
            }
            if(flag)cout<<0<<endl;
            else{
                int mini=INT_MAX;
                int mini2=INT_MAX;
                int start=-1;
                int start2=-1;
                for(int i=0;i<n-1;i++){
                    int temp=stoi(s.substr(i,2));
                    if(temp<mini){
                        mini=temp;
                        start=i;
                    }
                }
                for(int i=0;i<n-1;i++){
                    if(s[i]!='1' && s[i+1]!='1'){
                        int temp=stoi(s.substr(i,2));
                        if(temp<mini2){
                            mini2=temp;
                            start2=i;
                        }
                    }
                }
                // cout<<start2<<endl;
                if(start2==-1){
                    mini2=INT_MIN;
                    for(int i=0;i<n-1;i++){
                        if(s[i]=='1'){
                            int temp=stoi(s.substr(i,2));
                            // cout<<temp<<mini2<<endl;
                            if(temp>mini2){
                                mini2=temp;
                                start2=i;
                            }
                        }
                    }
                }
                
                int ans=0;
                for(int i=0;i<n;i++){
                    if(i!=start && i!=start+1 && s[i]!='1'){
                        ans+=s[i]-'0';
                    }
                    if(i==start){
                        ans+=mini;
                    }
                }
                int ans2=0;
                // cout<<mini2<<endl;
                for(int i=0;i<n;i++){
                    if(i!=start2 && i!=start2+1 && s[i]!='1'){
                        ans2+=s[i]-'0';
                    }
                    if(i==start2){
                        ans2+=mini2;
                    }
                }
                cout<<min(ans,ans2)<<endl;
            }
        }
        


    } 
    return 0;
}
