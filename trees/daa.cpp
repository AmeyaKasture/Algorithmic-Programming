void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }
void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }
int kosaraju(int V, vector<int> adj[]){
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }



//subordinates for the tree
void solve(int src, int par, vector<int>& ans)
{
    int subords = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}

//diameter
void eval_downPaths(int src, int par)
{
    int bestChildDownPath = 0;
    bool leaf = 1;
    for(int child : tree[src])
    {
        if(child != par)
        {
            leaf = 0;
            eval_downPaths(child, src);
            bestChildDownPath = max(bestChildDownPath, downPath[child]);
        }
    }
    if(leaf)downPath[src] = 0;
    else downPath[src] = 1 + bestChildDownPath;
}
 
void solve(int src, int par)
{
    int ans = 0;
    vector<int> childrenDownPaths;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src);
            childrenDownPaths.push_back(downPath[child]);
            ans = max(ans, diameter[child]);
        }
    }
    int numOfchildren = childrenDownPaths.size();
    sort(all(childrenDownPaths));
 
    if(numOfchildren == 0)diameter[src] = 0;
    else if(numOfchildren == 1)diameter[src] = 1 + childrenDownPaths[0];
    else diameter[src] = 2+childrenDownPaths[numOfchildren - 1]+childrenDownPaths[numOfchildren - 2];
 
    diameter[src] = max(diameter[src], ans);
}

//Tree distances-distance from a node to the farthest node in the tree
//ans array has the answers for all the nodes
vector<int> tree[200001];
int depth[200001];
int ans[200001];
 
void eval_depth(int src, int par)
{
    int src_depth = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            eval_depth(child, src);
            src_depth = max(src_depth, 1 + depth[child]);
        }
    }
    depth[src] = src_depth;
}
 
void solve(int src, int par, int par_ans)
{
    vector<int> prefixMax, suffixMax;
    // get depth of child nodes.
    for(int child : tree[src])
    {
        if(child != par)
        {
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }
    // build prefix and suffix
    for(int i = 1; i < prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
    for(int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
 
    //eval ans for every child c_no
    int c_no = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int op2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            int partial_ans = 1 + max(par_ans, max(op1,op2));
 
            solve(child, src, partial_ans);
            c_no++;
        }
    }
 
    //eval ans for src
    ans[src] = 1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
}



//total sum of distances from each node
vector<int> tree[200001];
ll subtreeAns[200001];
ll ans[200001];
int subtreeSize[200001];
 
void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            preprocessing(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
 
void solve(int src, int par, ll par_ans, int& totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
 

#include <iostream>

using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

// This code is contributed by Serjeel Ranjan





int lcslen = 0;
int dp[MAX][MAX];
int lcs(string str1, string str2, int len1, int len2,
									int i, int j)
{
	int &ret = dp[i][j];
	if (i==len1 || j==len2)return ret = 0;
	if (ret != -1)return ret;
	ret = 0;
	if (str1[i] == str2[j])ret = 1 + lcs(str1, str2, len1, len2, i+1, j+1);
	else ret = max(lcs(str1, str2, len1, len2, i+1, j),
    lcs(str1, str2, len1, len2, i, j+1));
	return ret;
}
void printAll(string str1, string str2, int len1, int len2,
			char data[], int indx1, int indx2, int currlcs)
{
	if (currlcs == lcslen)
	{
		data[currlcs] = '\0';
		puts(data);
		return;
	}
	if (indx1==len1 || indx2==len2)return;
	for (char ch='a'; ch<='z'; ch++)
	{
		bool done = false;
		for (int i=indx1; i<len1; i++)
		{
			if (ch==str1[i])
			{
			for (int j=indx2; j<len2; j++)
			{
				if (ch==str2[j] &&
				dp[i][j] == lcslen-currlcs)
				{
				data[currlcs] = ch;
				printAll(str1, str2, len1, len2, data, i+1, j+1, currlcs+1);
				done = true;
				break;
				}
			}
			}
			if (done)
				break;
		}
	}
}

void prinlAllLCSSorted(string str1, string str2)
{
	int len1 = str1.length(), len2 = str2.length();
	memset(dp, -1, sizeof(dp));
	lcslen = lcs(str1, str2, len1, len2, 0, 0);
	char data[MAX];
	printAll(str1, str2, len1, len2, data, 0, 0, 0);
}

// Driver program to run the case
int main()
{
	string str1 = "abcabcaa", str2 = "acbacba";
	prinlAllLCSSorted(str1, str2);
	return 0;
}


string smallestWindow(string s, string p)
    {
        if (s.size() < p.size()) {
            return "-1";
        }
        unordered_map<char, int> mp;
        for (auto& i : p)
            mp[i]++;
        string ans;
        int len = 1e9;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string curr = s.substr(i, j - i + 1);
                unordered_map<char, int> ms;
                for (auto& i : curr) {
                    ms[i]++;
                }
                bool f = 1;
                for (auto& i : mp) {
                    if (ms[i.first] < i.second) {
                        f = 0;
                    }
                }
                if (f) {
                    if (len > curr.size()) {
                        len = curr.size();
                        ans = curr;
                    }
                }
            }
        }
        return ans;
    }

// Back-end complete function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        int C[n];
        bool P[n][n];
        
        int i, j, k, L;
        for(i = 0;i < n;i++)
            P[i][i] = true;
        
        for(L = 2; L <= n;L++){
            for(i = 0;i < n-L+1;i++){
                j = i+L-1;   // set ending index
                if(L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = ((str[i] == str[j]) & P[i+1][j-1]);
            } 
        }   
        for(i = 0;i < n;i++){
            if(P[0][i])
                C[i] = 0;
            else{
                C[i] = INT_MAX;
                for(j = 0;j < i;j++){
                    if(P[j+1][i] == true & C[j]+1 < C[i])
                        C[i] = C[j]+1;
                }
            }
        }
        return C[n-1];
    }
};


int matrixMultiplication(int N, int arr[])
    {
        int dp[N+1][N+1];
        for(int i = 0;i < N;i++)dp[i][i] = 0;
        for(int L = 2;L < N;L++){
            for(int i = 1;i < N-L+1;i++){
                int j = i+L-1;
                dp[i][j] = INT_MAX;
                for(int k = i;k < j;k++){
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
            }
        }
        return dp[1][N-1];
    }


int NumberofLIS(int n, vector<int>&arr) {
        vector<int>dp(n,1),count(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++) {
          for(int prev=0;prev<i;prev++) {
              if(arr[prev]<arr[i] && 1 + dp[prev] > dp[i]) {
                  dp[i] = 1 + dp[prev];
                  count[i] = count[prev];
              }
              else if(arr[prev] < arr[i] && 1 + dp[prev] == dp[i]) {
                  count[i] += count[prev];
              }
           }
            if(dp[i]>maxi) {
              maxi = dp[i];
            }
        }
        int res=0;
        for(int i=0;i<n;i++) {
            if(dp[i]==maxi) {
                res += count[i];
            }
        }
        return res;
    }

//maximum valid parenthesis
int findMaxLen(string s)
{
    if (s.length() <= 1)
        return 0;

    // Initialize curMax to zero
    int curMax = 0;

    vector<int> longest(s.size(), 0);

    // Iterate over the string starting from second index
    for (int i = 1; i < s.length(); i++) 
    {
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0
            && s[i - longest[i - 1] - 1] == '(') 
        {
            longest[i]
                = longest[i - 1] + 2
                  + ((i - longest[i - 1] - 2 >= 0)
                  ? longest[i - longest[i - 1] - 2]
                  : 0);
            curMax = max(longest[i], curMax);
        }
    }
    return curMax;
}


int findLongestFromACell(int i, int j, int mat[n][n],
                         int dp[n][n])
{
    if (i < 0 || i >= n || j < 0 || j >= n)return 0;
    if (dp[i][j] != -1)return dp[i][j];
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
    if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
        x = 1 + findLongestFromACell(i, j + 1, mat, dp);

    if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1]))
        y = 1 + findLongestFromACell(i, j - 1, mat, dp);
 
    if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j]))
        z = 1 + findLongestFromACell(i - 1, j, mat, dp);
 
    if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
        w = 1 + findLongestFromACell(i + 1, j, mat, dp);
    return dp[i][j] = max({x, y, z, w, 1});
}

int shortest_path_sum(int** edges_list,int** dp_array,int visited,int mask,int position,int num_nodes)
    {
        /// The base case
        if(mask == visited)
        {
            return edges_list[position][0];
        }
        
        /// The check case to avaoid repeatation of the recursive call
        if(dp_array[mask][position] != -1)
        {
            return dp_array[mask][position];
        }
        
        /// main calculation part
        int ans = INT_MAX;
        for(int city=0;city<num_nodes;city++){

		if((mask&(1<<city))==0){

			int newAns = edges_list[position][city] + shortest_path_sum(edges_list,dp_array,visited,mask|(1<<city), city,num_nodes);
			ans = min(ans, newAns);
		}

//burst baloons
//Back-end complete function template in C++

class Solution
{
public:
    //Function to find the maximum number of coins that can be obtained.in burst baloon
    int maxCoins(int N, vector<int> &arr)
    {
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        for (int len = 1; len <= N; ++len)
        {
            for (int left = 1; left <= N - len + 1; ++left)
            {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                {
                    dp[left][right] = max(dp[left][right], arr[left - 1] * arr[k] * arr[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        //Returning the maximum number of coins.
        return dp[1][N];
    }
};
