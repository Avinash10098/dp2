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

int solve(int index , int w , int val[] , int wt[] , vector<vector<int>>&dp){
    if(index == 0){
        return ((int)w / wt[0]) * val[0];
    }

    if(dp[index][w] != -1){
        return dp[index][w];
    }

    int notTake = 0+ solve(index - 1, w, val, wt , dp);
    int take = INT_MIN;
    if(wt[index] <= w){
        take = val[index] + solve(index, w-wt[index], val, wt , dp);
    }
    return dp[index][w] =  max(take, notTake);
}


int knapSack(int n, int w, int val[], int wt[]){
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = wt[0]; i <= w; i++){
        dp[0][i] = (i/ wt[0]) * val[0];
    }
    for (int index = 1; index < n; index++){
        for (int t = 0; t <= w; t++){
            int notTake = 0 + dp[index - 1][t];
            int take = INT_MIN;
            if (wt[index] <= t)
            {
                take = val[index] + dp[index][t - wt[index]];
            }
            dp[index][t] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

int32_t main()
{
    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++){
        cin >> val[i];
    }
    for (int i = 0; i < n; i++){
        cin >> wt[i];
    }
    int w;
    cin >> w;
    cout<<knapSack(n, w, val, wt);
    return 0;
}