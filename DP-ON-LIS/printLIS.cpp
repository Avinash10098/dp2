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

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    for (int i = 0; i <= n-1; i++){
        hash[i] = i;
        for (int prev_Index = 0; prev_Index <= i - 1; prev_Index++){
            if(arr[prev_Index] < arr[i] && 1 + dp[prev_Index] > dp[i]){
                dp[i] = 1 + dp[prev_Index];
                hash[i] = prev_Index;
            }
        }
    }

    int lastIndex = -1;
    int ans = -1;
    for (int i = 0; i <= n-1; i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);  
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it : arr){
        cin >> it;
    }
    auto p= longestIncreasingSubsequence(n, arr);
    for(auto it: p){
        cout << it << " ";
    }
    return 0;
}