#include <bits/stdc++.h>
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define w(t)     \
    int t;       \
    cin >> t;    \
    while (t--)  \
    {            \
        solve(); \
    }
using namespace std;

const int MAX_NUM = 200;
vector<bool> is_prime(MAX_NUM + 1, true);
vector<pair<int, int>> possible;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_NUM; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_NUM; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    map<int, vector<int>> mp;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mp[A[i]].push_back(i + 1);
    }
    for (auto i : possible) {
        if (!mp[i.first].empty() && !mp[i.second].empty()) {
            for (int idx1 : mp[i.first]) {
                for (int idx2 : mp[i.second]) {
                    if (idx1 != idx2) {
                        cout << idx1 << " " << idx2 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    IO;
    sieve();
    for (int i = 1; i < 101; i++) {
        for (int j = i; j < 101; j++) {
            if (!is_prime[i + j]) {
                possible.push_back(make_pair(i, j));
            }
        }
    }
    w(t);
    return 0;
}
