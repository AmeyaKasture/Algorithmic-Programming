#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e8;
const long long MOD = 1e9 + 7;

long long mod_pow(long long b, long long e, long long m) {
    long long r = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            r = (r * b) % m;
        }
        b = (b * b) % m;
        e /= 2;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long pow_v = mod_pow(INF, n - 1, MOD);

    long long max_v = LLONG_MIN;

    for (int i = 0; i < n - 1; ++i) {
        long long val = arr[i] - arr[i + 1];
        long long cur_v = (val * pow_v) % MOD;
        if (cur_v > max_v) {
            max_v = cur_v;
        }
    }

    cout << max_v << endl;
    return 0;
}
