#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

  vector<pair<int,int>> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<pair<int,int>> &arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int divisor =10;
    vector<vector<pair<int,int>>> bucket;
    for(int divisor=10;divisor<=k;){
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i]%divisor,i});
        }
        mergeSort(temp, 0, n - 1);
        bucket.push_back(temp);
        divisor = divisor*10;
    } 

    for(auto it:bucket){
        for(auto i:it){
            cout<<arr[i.second]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
