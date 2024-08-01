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

int f(int index1 , int index2 , string &s1 , string &s2 , vector<vector<int>>&dp){
    if(index1 == 0 || index2 == 0)
        return 0;
    if(s1[index1-1] == s2[index2-1]){
        return 1 + f(index1 - 1, index2 - 1, s1, s2 , dp);
    }

    if(dp[index1][index2] !=-1){
        return dp[index1][index2];
    }

    return dp[index1][index2] = max(f(index1 - 1, index2, s1, s2 , dp), f(index1, index2 - 1, s1, s2 ,dp));
}


int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    // vector<vector<int>> dp(n+1, vector<int>(m + 1, -1));
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> prev(m + 1 , 0) , curr(m + 1 , 0);

    // for (int j = 0 ; j <= m; j++){
    //     prev[j] = 0;
    // }
    // for (int i = 0; i <= n; i++){
    //     dp[i][0] = 0;
    // }

    for (int index1 = 1; index1 <= n; index1++){
        for (int index2 = 1; index2 <= m; index2++){
            if (s1[index1 - 1] == s2[index2 - 1])
            {
                curr[index2] = 1+prev[index2 - 1];
            }
            else curr[index2] = max(prev[index2], curr[index2 - 1]);
        }
        prev = curr;
    }
    return prev[m];
}



int32_t main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    cout<<longestCommonSubsequence(s1, s2);
    return 0;
}