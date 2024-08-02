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

// int f(int index , int target , vector<int>&arr , vector<vector<int>>&dp){

//     if(index == 0){
//         if(target % arr[index] == 0){
//             return target / arr[index];
//         }
//         return 1e7;
//     }

//     if(dp[index][target] != -1)
//         return dp[index][target];

//     int notTake = 0 + f(index - 1, target, arr , dp);
//     int take = INT_MAX;
//     if(arr[index] <= target){
//         take = 1 + f(index, target - arr[index], arr , dp);
//     }
//     return dp[index][target] =  min(take, notTake);
// }

int solve(int n, int target, vector<int> &arr)
{
    // recursive apporach;
    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    vector<int> prev(target + 1), curr(target + 1);

    for (int i = 0; i <= target; i++)
    {
        if (i % arr[0] == 0)
        {
            prev[i] = i / arr[0];
        }
        else
        {
            prev[i] = 1e7;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notTake = 0 + prev[t];
            int take = INT_MAX;
            if (arr[index] <= t)
            {
                take = 1 + curr[t - arr[index]];
            }
            curr[t] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[target];
    if (ans >= 1e7)
        return -1;
    return ans;
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
    cout << solve(n, target, arr);

    return 0;
}