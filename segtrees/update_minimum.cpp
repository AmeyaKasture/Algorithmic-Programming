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
        return segtree[index]=min(lt,rt);
    }
    
    int retriver(int index,int l ,int r,int ql,int qr){
        if(l>qr || r<ql)return INT_MAX;
        if(ql<=l && qr>=r)return segtree[index];
        else{
            int mid=l+(r-l)/2;
            int lt=retriver(2*index+1,l,mid,ql,qr);
            int rt=retriver(2*index+2,mid+1,r,ql,qr);
            return min(lt,rt);
        }
    }

    int update(int index,int l,int r,int q,int k){
        if(q<l || q>r)return segtree[index];
        if(l==r)return segtree[index]=k;
        else{
            int mid=l+(r-l)/2;
            int lt=update(2*index+1,l,mid,q,k);
            int rt=update(2*index+2,mid+1,r,q,k);
            return segtree[index]=min(lt,rt);
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
        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            sgt.update(0,0,n-1,a-1,b);
        }
        if(type==2){
            cout<<sgt.retriver(0,0,n-1,a-1,b-1)<<endl;
        }
    }
  
    return 0;
}
