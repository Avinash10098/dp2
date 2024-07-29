#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
const int mod = 1e9 + 7;

class comparator
{
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    // if(dp[n] != -1)
    //     return dp[n];
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans += solve(n - i, dp);
    }
    return ans % mod;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << solve(n, dp);
}