#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
const int mod = 1e9 + 7;
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;

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

int solve(int target, vector<int> &arr, vector<int> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    int ans = 0;
    if (dp[target] != -1)
    {
        return dp[target];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        ans += solve(target - arr[i], arr, dp);
        dp[target] = ans % mod;
    }
    return dp[target];
}

int32_t main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    vector<int> dp(target + 1, -1);
    cout << solve(target, arr, dp) << endl;
}