#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node* up;
    Node(int data){
        this->val=data;
    }

};
int recur(Node* src, Node* dest,vector<int>& visited,int root,int t){
    // cout<<src->val<<endl;
    if(src==dest)return src->val;
    if(!src || visited[src->val-root]==1)return 1e7;
    visited[src->val-root]=1;
    int left=INT_MAX,right=INT_MAX,up=INT_MAX;
    if(src->left)left=src->val+t*abs(src->val-src->left->val)+recur(src->left,dest,visited,root,t);
    if(src->right)right=src->val+t*abs(src->val-src->right->val)+recur(src->right,dest,visited,root,t);
    if(src->up)up=src->val+t*abs(src->val-src->up->val)+recur(src->up,dest,visited,root,t);
    return min(left,min(right,up));
}



int main(){
    int root,n,t,src,dest,sp;
    cin>>root>>n>>t>>src>>dest>>sp;
    int i =root;
    // Node* root_n= new Node(root);
    // int f=-1;
    // map<int,Node*> mp;
    // mp[root]=root_n;
   
    // for(int j=i+1;j<i+n;j++){
    //     Node* temp=mp[i];
    //     if(f==-1){
    //         Node* np=new Node(j);
    //         mp[j]=np;
    //         temp->left= np;
    //         np->up=temp;
    //         f=1;
    //     }
    //     else if(f){
    //          Node* np=new Node(j);
    //         mp[j]=np;
    //         temp->right=np;
    //         np->up=temp;
    //         i++;
    //         f=-1;
    //     }

    // }
    // vector<int> visited(n+1,0);
    // int ans= recur(mp[src],mp[dest],visited,root,t)-src-dest;
    // cout<<sp*t-ans;


    int start=src-root;
    int end =dest -root;
    int cost=0;
    while(start!=end){
        if(start>end){
            cost+=root+start+abs(start-(start-1)/2)*t;
            cout<<root+start<<"\t";
            start=(start-1)/2;
            // cout<<root+start<<endl;
        }
        else if(start<end){
            cost+=root+end+abs(end-(end-1)/2)*t;
            cout<<root+end<<"\t";
            end=(end-1)/2;
            // cout<<root+end<<endl;
        }

    }
    cost-=src;
    cost-=dest;
    cout<<cost<<endl;
    cost+=root+start;
    cout<<t*sp-cost;
    return 0;
}


//count the numver of paths containing that node
void dfs1(int u = 1, int par = 1){
    in[u] = ++timer;
    p[u][0] = par;
    for(int i = 1; i < logN; i++)
        p[u][i] = p[p[u][i-1]][i-1];
    for(int v : G[u])
        if(v != par)
            dfs1(v, u);
    out[u] = ++timer;
}

void dfs2(int u = 1){
    for(int v : G[u]){
        if(v != p[u][0]){
            dfs2(v);
            sub[u] += sub[v];
        }
    }
}
bool ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}
int lca(int u, int v){
    if(ancestor(u, v))  return u;
    if(ancestor(v, u))  return v;
    for(int i = logN-1; i >= 0; i--)
        if(!ancestor(p[u][i], v))
            u = p[u][i];
    return p[u][0];
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs1();
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        int l = lca(a, b);
        sub[a]++; sub[b]++;
        sub[l]--;
        if(l != 1)
            sub[p[l][0]]--;
    }
    dfs2();
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    dp[1] = 1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    printf("%lld\n", dp[N]);}


void solve(){
    int n,m,k; see(n,m,k);
    //https://en.wikipedia.org/wiki/K_shortest_path_routing
    vii adj[n+1];
    rep(i,0,m){
        int a,b,w; see(a,b,w);
        adj[a].pb({b,w});
    }
    priority_queue<pii> q;
    q.push({0,1});
    int vis[n+1]={0};
    while(!q.empty() && vis[n]<k){
        int a = q.top().S;
        int d = q.top().F;
        q.pop(); vis[a]++;
        if (a==n) put(-d);
        if (vis[a]<=k){
            for (auto [b,w]: adj[a]){
                q.push({d-w,b});
            }
        }
    }
}
cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)CLOCKS_PER_SEC<<endl;


//path l-1
int getSize(int u = 1, int p = -1){
    sz[u] = 1;
    for(int v : G[u])
        if(v != p && !vis[v])
            sz[u] += getSize(v, u);

    return sz[u];
}

int centroid(int u, int p, int n){
    for(int v : G[u])x
        if(v != p && !vis[v] && sz[v] > n/2)
            return centroid(v, u, n);

    return u;
}

void dfs(int u, int p, bool t, int d = 1){
    if(d > K)   return;

    deepest = max(deepest, d);
    if(t)       cnt[d]++;
    else        ans += cnt[K-d];

    for(int v : G[u])
        if(v != p && !vis[v])
            dfs(v, u, t, d+1);
}

void solve(int u = 1){
    int c = centroid(u, -1, getSize(u));
    vis[c] = true;
    deepest = 0;

    for(int v : G[c]){
        if(!vis[v]){
            dfs(v, c, false);
            dfs(v, c, true);
        }
    }
    fill(cnt+1, cnt+deepest+1, 0);

    for(int v : G[c])
        if(!vis[v])
            solve(v);
}
