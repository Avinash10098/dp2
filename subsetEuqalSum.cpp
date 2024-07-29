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

bool solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }

    if (index == 0)
    {
        return arr[index] == target;
    }

    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = solve(arr, index - 1, target, dp);
    int take = false;
    if (target >= arr[index])
    {
        take = solve(arr, index - 1, target - arr[index], dp);
    }
    return dp[index][target] = take | notTake;
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum & 1)
    {
        return false;
    }
    int target = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(nums, n - 1, target, dp);
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
    cout << canPartition(arr);
}