#include <bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(st.empty()||(arr[i]>=arr[st.top()]))st.push(i);
        else{
            while((!st.empty())&& arr[i]<arr[st.top()]){
                int ind= st.top();
                ans[ind]=i;
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        int ind= st.top();
        ans[ind]=-1;
    }
    return ans;
}