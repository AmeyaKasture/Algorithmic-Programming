#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define int long long


class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node* top;
        Node(int data){
            this->data=data;
        }
};
Node* target;
map<Node*,int> mp;

Node* build(vector<int>& postorder,int left,int right,int t){
    if(left>right)return NULL;
    Node* root= new Node(postorder[right]);
    // cout<<left<<"\t"<<right<<endl;
    mp[root]=0;
    if(postorder[right]==t)target=root;
    if(left==right)return root;
    int i =left;
    right--;
    while(i<right && postorder[i]<postorder[right+1]){
        i++;
    }
    i--;
    // cout<<postorder[i]<<"\t"<<i<<endl;
    Node* lt=build(postorder,left,i,t);
    Node* rt=build(postorder,i+1,right,t);
    root->left=lt;
    if(lt)lt->top=root;
    root->right=rt;
    if(rt)rt->top=root;
    return root;
}


int32_t main(){
    int n,t;
    cin>>n>>t;
    vector<int> postorder(n);
    for(int i=0;i<n;i++)cin>>postorder[i];
    Node* root= build(postorder,0,n-1,t);
    queue<Node*> q;
    int maxi=0;
    int time=-1;
    q.push(target);
    while(!q.empty()){
        time++;
        int n=q.size();
        maxi=max(maxi,n);
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            mp[temp]=1;
            if(temp->left && mp[temp->left]==0)q.push(temp->left);
            if(temp->right && mp[temp->right]==0)q.push(temp->right);
            if(temp->top && mp[temp->top]==0)q.push(temp->top);
        }
    }
    cout<<time<<" "<<maxi<<endl;
    return 0;
}
