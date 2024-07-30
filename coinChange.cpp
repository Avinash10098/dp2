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


int solve(vector<int>&arr , int index  , int amount , vector<vector<int>>&dp){

    if(index == 0){
        if(amount % arr[index] == 0 )
            return amount / arr[index];
        return 1e7;
    }
    if(dp[index][amount] != -1){        //Memoization
        return dp[index][amount];
    }

    int notTake = solve(arr, index - 1, amount , dp);
    int take = INT_MAX;
    if(arr[index] <= amount){
        take = 1 + solve(arr, index, amount - arr[index] , dp);
    }
    return dp[index][amount] = min(take, notTake);
}

// int coinChange(vector<int> &arr, int amount)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
//     // int ans =  solve(arr, n - 1, amount ,dp);
//     // if(ans >= 1e7){
//     //     return -1;
//     // }
//     // return ans;
//     for (int i = 0; i <= amount; i++){
//         if(i % arr[0] == 0){
//             dp[0][i] = i / arr[0];  //tabulation
//         }else{
//             dp[0][i] = 1e7;
//         }
//     }

//     for (int index = 1; index < n; index++){
//         for (int t = 0; t <= amount; t++){
//             int notTake = dp[index - 1][t];
//             int take = 1e7;
//             if (arr[index] <= t)
//             {
//                 take = 1 + dp[index][t-arr[index]];
//             }
//             dp[index][t] = min(take, notTake);
//         }
//     }
//     int ans =  dp[n-1][amount];
//     if(ans >= 1e7)
//         return -1;
//     return ans;
// }

int coinChange(vector<int> &arr, int amount)
{
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    // int ans =  solve(arr, n - 1, amount ,dp);
    // if(ans >= 1e7){
    //     return -1;
    // }
    // return ans;

    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % arr[0] == 0)
        {
            prev[i] = i / arr[0]; // space-optimazation
        }
        else
        {
            prev[i] = 1e7;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int t = 0; t <= amount; t++)
        {
            int notTake = prev[t];
            int take = 1e7;
            if (arr[index] <= t)
            {
                take = 1 + curr[t - arr[index]];
            }
            curr[t] = min(take, notTake);
        }
        prev = curr;
    }
    int ans = prev[amount];
    if (ans >= 1e7)
        return -1;
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    int amount;
    cin >> amount;
    cout << coinChange(arr, amount);
    return 0;
}