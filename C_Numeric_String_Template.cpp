#include <bits/stdc++.h>
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef unsigned long int ll;
#define int long long
typedef long double LD;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define w(t)     \
    int t;       \
    cin >> t;    \
    while (t--)  \
    {            \
        solve(); \
    }
using namespace std;
const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> arrMp;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrMp[arr[i]].push_back(i);
    }

    int m;
    cin >> m;

    while (m--) {
        map<char, vector<int>> strMp;
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) 
            strMp[s[i]].push_back(i);

        bool possible = true;

        for (auto &it : arrMp) {
            if (strMp.count(s[it.second[0]]) == 0 || strMp[s[it.second[0]]].size() != it.second.size()) {
                possible = false;
                break;
            }
            for (int i = 0; i < it.second.size(); i++) {
                if (strMp[s[it.second[0]]][i] != it.second[i]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) break;
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main() {
    IO;
    w(t);
    return 0;
}
