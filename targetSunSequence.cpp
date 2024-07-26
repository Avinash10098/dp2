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

bool solve(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (index == 0)
        return arr[0] == sum;

    if (dp[index][sum] != -1)
        return dp[index][sum];
    int notTake = solve(arr, sum, index - 1, dp);
    int take = false;
    if (sum >= arr[index])
    {
        take = solve(arr, sum - arr[index], index - 1, dp);
    }
    return dp[index][sum] = take | notTake;
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    // delecration of 2D array
    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    // return solve(arr, sum, n - 1 , dp);

    // this does't work for will i will fixesd it;
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= sum)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= sum; k++)
        {
            bool notTake = dp[i - 1][k];
            bool take = false;
            if (k >= arr[i])
            {
                take = dp[i - 1][k - arr[i]];
            }
            dp[i][k] = take | notTake;
        }
    }
    return dp[n - 1][sum];
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    int t;
    cin >> t;
    cout << isSubsetSum(arr, t);
}