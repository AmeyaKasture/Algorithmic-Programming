
#include <bits/stdc++.h>
#define int long long

using namespace std;
int ans=-1;
// void solve(int ind,int flr_a,int flr_b,int a,int b, vector<vector<int>>& arr,int& cost){
//     int n=arr.size();
//     if(ans!=-1 && cost>ans){
//         return;
//     }
//     if(flr_a !=0 && flr_b != 0 && flr_a * b == a* flr_b){
//             if(ans==-1){
//                 ans=cost;
//             }
//             else{
//                 ans=min(ans,cost);
//             }
//             return;
//         }
//     if(ind == n){
//         return ;
//     }
   
//     cost=cost+arr[ind][2];
//     solve(ind+1,flr_a +arr[ind][0],flr_b+arr[ind][1],a,b,arr,cost);
//     cost
//     solve(ind+1,flr_a,flr_b,a,b,arr,cost);

// }
signed  main()
{
    int n;
    cin>>n;
    vector<int> arr(n+1,0);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        arr[x-1]++;
        arr[y-1]++;
    }
    set<pair<int,int>>s;  
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            temp+=arr[j];
            s.insert({temp,j-i+1});
        }
    }
    cout<<s.size()+1<<endl;
    // vector<int>good;
    // vector<int>count(n+1);
    // //find only unique elements while storing count of repeated     
    // for(int i=0;i<arr.size();i++){
    //     if(i==0){
    //         good.push_back(arr[i]);
    //     }
    //     else{
    //         while(arr[i]==arr[i-1] && i<arr.size()){
    //             i++;
    //         }
            
    //         if(arr[i]!=arr[i-1]){
    //             good.push_back(arr[i]);
    //         }
    //     }
    // }
    // unordered_map<int,int>count;
    // //store count of repeated elements in a map
    // for(int i=0;i<arr.size();i++){
    //     count[arr[i]]++;
    // }
   


	

	return 0;
}