#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007

class seg_tree{
    public:
    vector<int> seg;
    int n;
    seg_tree(int n){
        this->n=n;
        seg.resize(4*n);
    }

    int build(vector<int> & arr,int index, int l, int r){
        if(l==r){
            seg[index]=arr[l];
            return arr[l];
        }
        int mid=l+(r-l)/2;
        int left=build(arr,2*index+1,l,mid);
        int right=build(arr,2*index+2,mid+1,r);
        seg[index]=left+right;
        return seg[index];
    }

    int sum(int index, int l, int r, int ql, int qr){
       if(ql>r || qr<l)return 0;
       if(ql<=l && qr>=r)return seg[index];
       else{
            int mid=(l+r)/2;
            return sum(2*index+1,l,mid,ql,qr)+sum(2*index+2,mid+1,r,ql,qr);
       }
    }

};



signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> seg(4*n);
    seg_tree st(n);
    st.build(arr,0,0,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.sum(0,0,n-1,l-1,r-1)<<endl;
    }
    
    return 0;
}
