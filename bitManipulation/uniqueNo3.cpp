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

int solve(vector<int> &arr, int n)
{
    vector<int> res(64);
    for (int i = 0; i < 64; i++)
    {
        res[i] = 0;
    }
    for (auto it : arr)
    {
        for (int i = 30; i >= 0; i--)
        {
            int mask = (1 << i);
            if ((it & mask) > 0)
            {
                res[i]++;
            }
        }
    }
    // print(res);
    int p = 1;
    int ans = 0;
    for (int i = 0; i < res.size(); i++){
        res[i] = res[i] % 3;
        // cout << res[i] << " ";
        ans += (res[i] * p);
        p = p << 1;
    }
    cout << ans << endl;
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    solve(arr, n);
    return 0;
}