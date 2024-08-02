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

int f(int index, int t, vector<int> &arr , vector<vector<int>>&dp)
{
    if (index == 0)
    {
        return (t % arr[index] == 0);
    }

    if(dp[index][t] != -1){
        return dp[index][t];
    }

    int notTake = 0 + f(index - 1, t, arr , dp);
    int take = 0;
    if (arr[index] <= t)
    {
        take = f(index, t - arr[index], arr , dp);
    }
    return dp[index][t] = (take + notTake)%mod;
}

// int solve(int n, int t, vector<int> &arr)
// {
//     vector<vector<int>> dp(n ,vector<int>(t + 1, -1));
//     return f(n - 1, t, arr , dp);
   
//     for (int i = 0; i <= t; i++){
//         if(i % arr[0] == 0){
//             dp[0][i] = 1;
//         }                //Tabulation
//     }

//     for (int index = 1; index < n; index++){
//         for (int j = 0; j <= t; j++){
//             int notTake = 0 + dp[index - 1][j];
//             int take = 0;
//             if (arr[index] <= j)
//             {
//                 take = dp[index][j - arr[index]];
//             }
//             dp[index][j] = take + notTake;
//         }
//     }
//     return dp[n - 1][t];
// }

int solve(int n, int t, vector<int> &arr)
{
    // vector<vector<int>> dp(n, vector<int>(t + 1, -1));
   
    // return f(n - 1, t, arr, dp);

    vector<int> prev(t + 1, 0);
    vector<int> curr(t + 1, 0);

    for (int i = 0; i <= t; i++)
    {
        if (i % arr[0] == 0)
        {
            prev[i] = 1;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int j = 0; j <= t; j++)
        {
            int notTake = 0 + prev[j];
            int take = 0;
            if (arr[index] <= j)
            {
                take = curr[j - arr[index]];
            }
            curr[j] = (take + notTake)%mod;
        }
        prev = curr;
    }
    return prev[t];
}

int32_t main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    cout << solve(n, t, arr);
    return 0;
}