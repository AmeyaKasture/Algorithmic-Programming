#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007


class SGT{
    public:
    int n;
    vector<int> segtree;

    SGT(int n){
        this->n=n;
        segtree.resize(4*n);
    }

    int build(vector<int> & arr,int index,int l,int r){
        if(l==r)return segtree[index]=arr[l];
        int mid=l+(r-l)/2;
        int lt=build(arr,2*index+1,l,mid);
        int rt=build(arr,2*index+2,mid+1,r);
        return segtree[index]=lt^rt;
    }

    int retriver(int index,int l,int r,int ql,int qr){
        if(l>qr || r<ql)return 0;
        if(ql<=l && qr>=r)return segtree[index];
        else {
            int mid=l+(r-l)/2;
            int lt=retriver(2*index+1,l,mid,ql,qr);
            int rt=retriver(2*index+2,mid+1,r,ql,qr);
            return lt^rt;
        }
    }

};


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    SGT st(n);
    st.build(arr,0,0,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.retriver(0,0,n-1,l-1,r-1)<<endl;
    }
    return 0;
}
