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

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> pref(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    string s; cin >> s;
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i];
    int count = n - 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            while(count > i and s[count] != 'R') count--;
            if(count > i) {
                ans += pref[count] - (i > 0 ? pref[i - 1] : 0);
                cout << i << " " << count << endl;
                count--;
                cout << ans << endl;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    IO;
    // solve();
    w(t);
    return 0;
}



