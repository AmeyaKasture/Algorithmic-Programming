#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int count_good_partitions(const string& S, const vector<int>& A, int K) {
    int N = S.size();
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;

    vector<vector<int>> prefix(N + 1, vector<int>(26, 0));
    
    // Build the prefix sum array
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 26; ++j) {
            prefix[i + 1][j] = prefix[i][j];
        }
        prefix[i + 1][S[i] - 'a']++;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j > 0; --j) {
            bool valid = true;
            for (int c = 0; c < 26; ++c) {
                if (prefix[i][c] - prefix[j - 1][c] > A[c]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
            
            for (int k = 1; k <= K; ++k) {
                dp[i][k] = (dp[i][k] + dp[j - 1][k - 1]) % MOD;
            }
        }
    }
    
    return dp[N][K];
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(26);
    for (int i = 0; i < 26; i++) cin >> arr[i];
    int k;
    cin >> k;

    cout << count_good_partitions(s, arr, k) << endl;

    return 0;
}
