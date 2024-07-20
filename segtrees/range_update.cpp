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
        return segtree[index]=lt+rt;
    }
    
    int retriver(int index,int l ,int r,int q){
        if(q<l ||  q>r)return 0;
        if(l==r)return segtree[index];
        else{
            int mid=l+(r-l)/2;
            int lt=retriver(2*index+1,l,mid,q);
            int rt=retriver(2*index+2,mid+1,r,q);
            return lt+rt;
        }
    }

    int update(int index,int l,int r,int ql,int qr,int k){
        if(l>qr || r<ql)return segtree[index];
        if(l==r){
            segtree[index]+=k;
            return segtree[index];
        else{
            int mid=l+(r-l)/2;
            int lt=update(2*index+1,l,mid,ql,qr,k);
            int rt=update(2*index+2,mid+1,r,ql,qr,k);  
            segtree[index]=lt+rt; 
            return segtree[index];
        }
    }

};


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    SGT sgt(n);
    sgt.build(arr,0,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b,c;
            cin>>a>>b>>c;
            sgt.update(0,0,n-1,a-1,b-1,c);
        }
        if(type==2){
            int k;
            cin>>k;
            cout<<sgt.retriver(0,0,n-1,k-1)<<endl;
        }
    }
  
    return 0;
}
