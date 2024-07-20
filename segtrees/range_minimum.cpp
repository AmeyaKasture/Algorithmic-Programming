#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define mod 1000000007


class seg_tree{
    public:
    int n;
    vector<int> segtree;
    seg_tree(int n){
        this->n=n;
        segtree.resize(4*n);
    }

    int build(vector<int> & arr,int index,int l,int r){
        if(l==r){
            segtree[index]=arr[l];
            return arr[l];
        }
        else{
            int mid=l+(r-l)/2;
            int left=build(arr,2*index+1,l,mid);
            int right=build(arr,2*index+2,mid+1,r);
            segtree[index]=min(left,right);
            return segtree[index];
        }
    }

    void print(){
        for(auto it:segtree)cout<<it<<" ";
        cout<<endl;
    }

    int mini(int index,int l ,int r,int ql ,int qr){
        if(ql>r || qr<l)return INT_MAX;
        else if(ql<=l && qr>=r)return segtree[index];
        else{
            int mid=(l+r)/2;
            return min(mini(2*index+1,l,mid,ql,qr),mini(2*index+2,mid+1,r,ql,qr));
        }
    }
};



signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // for(auto it:arr)cout<<it<<" ";
    // cout<<endl;
    seg_tree st(n);
    st.build(arr,0,0,n-1);
    // st.print();
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<st.mini(0,0,n-1,l-1,r-1)<<endl;
    }
    
    return 0;
}
