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
    
    int build(vector<int> &arr,int index,int l,int r){
        if(l==r)return segtree[index]=arr[l];
        int mid=l+(r-l)/2;
        int lt=build(arr,2*index+1,l,mid);
        int rt=build(arr,2*index+2,mid+1,r);
        // cout<<l<<" "<<r<<" "<<lt<<" "<<rt<<endl;
        return segtree[index]=lt+rt;
    }

    int retriver(int index,int l,int r,int ql,int qr){
        if(l>qr || r<ql)return 0;
        if(ql<=l  && qr>=r)return segtree[index];
        else{
            int mid=l+(r-l)/2;
            return retriver(2*index+1,l,mid,ql,qr)+retriver(2*index+2,mid+1,r,ql,qr);
        }
    }

    void update(int index,int l, int r, int q,int k,int og){
        if(q<l || q>r)return;
        else{
            segtree[index]+=k-og;
            if(l==r)return;
            int mid=l+(r-l)/2;
            update(2*index+1,l,mid,q,k,og);
            update(2*index+2,mid+1,r,q,k,og);
        }
    }

};


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    seg_tree sgt(n);
    sgt.build(arr,0,0,n-1);
    while(q--){
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            sgt.update(0,0,n-1,a-1,b,arr[a-1]);
            arr[a-1]=b;
        }
        if(type==2){
            cout<<sgt.retriver(0,0,n-1,a-1,b-1)<<endl;
        }
    }
    
    return 0;
}
