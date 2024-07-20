#include <bits/stdc++.h>

using namespace std;
#define int long long

int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n,-1),right(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty())st.push(i);
            else{
                if(heights[i]>=heights[st.top()])st.push(i);
                else{
                    while(!st.empty() && heights[i]<heights[st.top()]){
                        int t=st.top();
                        st.pop();
                        right[t]=i;
                        // cout<<t<<endl;
                    }
                    st.push(i);
                }  
            }
        }
        for(int i=n-1;i>=0;i--){
            if(st.empty())st.push(i);
            else{
                if(heights[i]>=heights[st.top()])st.push(i);
                else{
                    while(!st.empty() && heights[i]<heights[st.top()]){
                        int t=st.top();
                        st.pop();
                        left[t]=i;
                    }
                    st.push(i);
                }  
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(right[i]-left[i]-1)*heights[i]);
        }
        return maxi;


}

signed main(){
    int n;
    // cin>>n;
    // vector<int> heights(n);
    // for(int i=0;i<n;i++){
    //     cin>>heights[i];
    // }
    string a ="11"+11;
    cout<<endl;
   return 0;
}
