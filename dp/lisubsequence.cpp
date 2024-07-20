#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// #define int long long


long long maxsub(vector<int>&v){
    long long n= v.size();
    vector<int> dp;
    for(int i=0;i<n;i++){
        int temp=v[i];
        auto it=lower_bound(v.begin(),v.end(),temp);
        if(it!=dp.end()){
            int index = it-dp.begin();
            cout<<dp.size()<<"\t"<<index<<endl;
            dp[index]=temp;
        }
        else dp.push_back(temp);
    }
    return dp.size();
    

void print(vector<pair<int,int>> values){
    for(auto& val: values) {
        cout<<"("<<val.first<<","<<val.second<<")"<<" ";
    }
    cout<<endl;
}
}

       
void insertt(vector<pair<int,int>>& arr){
    int n =arr.size();
    for(int i=1;i<n;i++){
        auto key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j].first>key.first){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


void merger(vector<pair<int,int>>& arr,int left, int mid,int right,vector<int>&ans){
    vector<pair<int,int>> lsub(arr.begin()+left,arr.begin()+mid+1);
    vector<pair<int,int>> rsub(arr.begin()+mid+1,arr.begin()+right+1);
    lsub.push_back({INT_MAX,INT_MAX});
    rsub.push_back({INT_MAX,INT_MAX});
    int l=0;
    int r=0;
    for(int i=left;i<=right;i++){
        if(lsub[l].first<=rsub[r].first){
            arr[i]=lsub[l];
            l++;
        }
        else{
            arr[i]=rsub[r];
            r++;
        }
    }
}


void merge_sort(vector<pair<int,int>>& arr,int left, int right,vector<int> & ans){
    if(left>=right)return;
    int mid=(left+right)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merger(arr,left,mid,right);
}






signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> values(n);
    for(int i=0;i<n;i++){
        cin>>values[i].first;
        values[i].second=i;
    }
    print(values);
    // insertt(values);
    merge_sort(values,0,4,ans);
    vector<int> ans(n,1);    
    print(values);
  return 0;
}
