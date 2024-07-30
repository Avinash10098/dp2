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
int solve(int arr[], int index, int sum, int n, vector<vector<int>> &dp)
{
    if (sum < 0)
    {
        return 0;
    }

    if (index == n)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[index][sum] != -1)
        return dp[index][sum];

    int ans = solve(arr, index + 1, sum, n, dp);
    ans += solve(arr, index + 1, sum - arr[index], n, dp);
    dp[index][sum] = ans % mod;
    return dp[index][sum];
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return solve(arr, 0, sum, n, dp);
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    cout << perfectSum(arr, n, sum);
    return 0;
}