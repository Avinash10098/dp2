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

int f(int curr_index, vector<int> &arr, int prev_index, int n, vector<vector<int>> &dp)
{
    if (curr_index == n)
        return 0;

    if (dp[curr_index][prev_index + 1] != -1) //cordinate shipting
    {
        return dp[curr_index][prev_index + 1];
    }

    int notTake = 0 + f(curr_index + 1, arr, prev_index, n, dp); // not Take;
    int take = 0;
    if (prev_index == -1 || arr[curr_index] > arr[prev_index])
    {
        take = 1 + f(curr_index + 1, arr, curr_index, n, dp); // take
    }
    return dp[curr_index][prev_index + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int curr_index = n-1 ; curr_index >= 0; curr_index--){
        for (int prev_index = curr_index - 1; prev_index >= -1; prev_index--){
            int notTake = 0 + next[prev_index+1]; // not Take;
            int take = 0;
            if (prev_index == -1 || arr[curr_index] > arr[prev_index])
            {
                take = 1 + next[curr_index+1]; // take
            }
            curr[prev_index + 1] = max(take, notTake);
        }
        next = curr;
    }

    return curr[0];
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    cout << lengthOfLIS(arr);
    return 0;
}