#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;


void print(vector<int> v){
    for(auto it:v)cout<<it<<"\t";
    cout<<endl;
}
//largest lexical subsequence
int main(){
  int t;
  cin>> t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;i<n;i++){
       
        if(st.empty() || s[st.top()]>=s[i])st.push(i);
        else{
            while(!st.empty() && s[i]>s[st.top()] ){
                st.pop();
            }
            st.push(i);
        }
    }
        int m= st.size();
        vector<int> v(m);
        for(int i= m-1;i>=0;i--){
            v[i]=st.top();
            st.pop();
        }
        char last=s[v[0]];
        int j =1;
        int dup=0;
        for(int i=1;i<m;i++){
            if(s[v[i]]!=last)break;
            dup++;
        }
        for (int i = 0; i < m/2; i++) 
        {
            swap(s[v[i]],s[v[m-i-1]]);
        }
        int ans=m-1-dup;
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]){
                ans=-1;
                break;
        }
    }
    cout<<ans<<endl;
  }
  return 0;
}
