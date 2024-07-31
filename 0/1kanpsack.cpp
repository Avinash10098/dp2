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

int solve(vector<int> &weight, vector<int> &value, int index, int maxWeight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }                           //memoization
    }
    if (dp[index][maxWeight] != -1)
    {
        return dp[index][maxWeight];
    }
    int notTake = 0 + solve(weight, value, index - 1, maxWeight, dp);
    int take = INT_MIN;
    if (weight[index] <= maxWeight)
    {
        take = value[index] + solve(weight, value, index - 1, maxWeight - weight[index], dp);
    }
    return dp[index][maxWeight] = max(notTake, take);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    for (int i = weight[0]; i <= maxWeight; i++){
        dp[0][i] = value[0];
    }

    for (int index = 1; index < n ; index++){
        for (int mw = 0; mw <= maxWeight; mw++){
            int notTake = 0 + dp[index-1][mw];
            int take = INT_MIN;
            if (weight[index] <= mw)
            {
                take = value[index] + dp[index - 1][maxWeight - weight[index]];
            }
            dp[index][mw] = max(notTake, take);
        }
    }

    return dp[n - 1] [maxWeight];
}

int32_t main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> weight(n), value(n);
        for(auto &it : weight){
            cin >> it;
        }
        for (auto &it : value)
        {
            cin >> it;
        }
        int maxWeight;
        cin >> maxWeight;
        cout << knapsack(weight, value, n, maxWeight)<<endl;
    }
    return 0;
}