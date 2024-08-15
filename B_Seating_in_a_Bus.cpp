#include <bits/stdc++.h>
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef unsigned long int ll;
#define int long long
typedef long double LD;
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
const int N = 1e5+10;

int accumulate(vector<int> &arr) {
    int n = arr.size(), sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum;
}

void solve()
{
    int n; cin >> n;
    vector<int> arr(n);
    map<int, bool> mp; 
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = true;
        if(i > 0 and (!mp[arr[i] - 1] and !mp[arr[i] + 1])) ok = false;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main()
{
    IO;
    // solve();
    w(t);
    return 0;
}



