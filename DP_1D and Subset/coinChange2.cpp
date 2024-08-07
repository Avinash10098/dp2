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

int solve(int index, vector<int> &arr, int amount, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return (amount % arr[index] == 0);
    }

    if (dp[index][amount] != -1)
        return dp[index][amount];
    int notTake = solve(index - 1, arr, amount, dp);
    int take = 0;
    if (arr[index] <= amount)
    {
        take = solve(index, arr, amount - arr[index], dp);
    }
    return dp[index][amount] = take + notTake;
}

int change(int amount, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++){
        if(i % arr[0] == 0){
            prev[i] = 1;
        }
    }

    for (int index = 1; index < n; index++){
        for (int t = 0; t <= amount; t++){
            int notTake = prev[t];
            int take = 0;
            if (arr[index] <= t)
            {
                take = curr[t-arr[index]];
            }
            curr[t] = take + notTake;
        }
        prev = curr;
    }
    return prev[amount];
    // return solve(n - 1, arr, amount, dp);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    int amount;
    cin >> amount;
    cout << change(amount, arr);
    return 0;
}