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

int f(vector<int>&arr , int index , vector<int>&dp){
    if(index == 0)
        return arr[index];
    if(index < 0)
        return 0;

    if(dp[index] != -1){
        return dp[index];
    }

    int pick = arr[index] + f(arr, index - 2 ,dp);
    int notPick = 0 + f(arr, index - 1 , dp);
    return dp[index] = max(pick, notPick);
}

int helper(vector<int>&arr){
    int n = arr.size();
    // vector<int>dp(n, -1);
    // return f(arr, n - 1 , dp);
    // spaceOptimization code !
    int prev = arr[0];
    int prev2 = 0;
    // dp[0] = arr[0];

    for (int i = 1; i < n; i++){
        int pick = arr[i];
        if(i > 1){
            pick += prev2;
        }
        int notPick = 0 + prev;
        int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    // return dp[n - 1];
    return prev;
}

int solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin >> it;
    }

    if(n == 1){
        return arr[0];
    }
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++){
        if(i != 0)
            temp1.push_back(arr[i]);
        if(i != n-1)
            temp2.push_back(arr[i]);
    }
    int ans1 = helper(temp1);
    int ans2 = helper(temp2);
    return max(ans1, ans2);
}

int32_t main()
{
    cout<<solve();
}